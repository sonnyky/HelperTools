import imageio
import os
import sys
import argparse

from PIL import Image
import glob

parser = argparse.ArgumentParser()
parser.add_argument('-v', '--video', type=str, help="Path to video file")
parser.add_argument('-i', '--images', type=str, help='Path to folder containing images')
parser.add_argument('-t', '--type', type=str, help="Target format")
args = parser.parse_args()

if args.video and not args.type:
    raise RuntimeError(
        "Please specify both path to file and format type")

if args.images and args.video:
    raise ValueError("Incorrect command line parameters! \"-i\" cannot be used with \"-v\"!")

class TargetFormat(object):
    GIF = "gif"
    MP4 = "mp4"
    AVI = "avi"


def convertFile(inputpath, targetFormat):
    """Reference: http://imageio.readthedocs.io/en/latest/examples.html#convert-a-movie"""
    outputpath = os.path.splitext(inputpath)[0] + "." + targetFormat
    print("converting\r\n\t{0}\r\nto\r\n\t{1}".format(inputpath, outputpath))

    reader = imageio.get_reader(inputpath)
    fps = reader.get_meta_data()['fps']

    writer = imageio.get_writer(outputpath, fps=fps)
    for i, im in enumerate(reader):
        sys.stdout.write("\rframe {0}".format(i))
        sys.stdout.flush()
        writer.append_data(im)
    print("\r\nFinalizing...")
    writer.close()
    print("Done.")

def convertImagesToGif(inputPath):
    outputpath = os.path.splitext(inputPath)[0] + ".gif"
    # Create the frames
    frames = []
    imgs = glob.glob(os.path.join(inputPath, '*.png'))
    for i in imgs:
        new_frame = Image.open(i)
        frames.append(new_frame)

    # Save into a GIF file that loops forever
    frames[0].save(os.path.join(inputPath, 'converted.gif'), format='GIF',
                   append_images=frames[1:],
                   save_all=True,
                   duration=300, loop=0)

if args.video and args.type:
    convertFile(args.video, args.type)

if args.images:
    convertImagesToGif(args.images)