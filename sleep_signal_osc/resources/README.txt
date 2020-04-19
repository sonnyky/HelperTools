This is a combination of 2 utility tools to generate Ctrl Break and handle that event accordingly. This can be useful for automating clean shutdowns in Windows environments.
The process which catches this Ctrl Break event can choose to do any necessary cleanup before shutting down.

Composition
・sendsignal.exe
This is an application that sends a Ctrl Break event to another process
The original URL is as follows :
URL：http://web.archive.org/web/20170909040729/http://www.latenighthacking.com/projects/2003/sendSignal/

・sleep_signal_osc.exe
A sample application that handles a Ctrl Break event.
This application sends an OSC message to localhost:7777 when it receives a Ctrl Break event.
The OSC channel is /custom_interrupt and the message sent is "finish"

・stop.bat
A sample stop script, when this is run, it will search for a process called "sleep_signal_osc" from the Windows Tasklist and then
calls sendsignal.exe to send the Ctrl Break event.

Usage
・Launch sleep_signal_osc
・Use Task Scheduler to schedule the execution of stop.bat
・When stop.bat runs, sleep_signal_osc will send the message "finish" to /custom_interrupt 10 times before exiting
・You can use this utility to send the "finish" message to applications that otherwise cannot catch t
・You can avoid polling for time in your application to detect when to exit your application

To change to use other ports
-port 5001

Example
sleep_signal_osc.exe -port 5001