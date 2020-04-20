#### Usage
* Launch sleep_signal_osc.exe
* Use Task Scheduler to schedule the execution of stop.bat
* When stop.bat runs, sleep_signal_osc will send the message "finish" to /custom_interrupt 10 times before exiting
* You can use this utility to send the "finish" message to applications that otherwise cannot catch it
* You can avoid polling for time in your application to detect when to exit your application

To change to use other ports
-port 5001

Example
sleep_signal_osc.exe -port 5001

Also refer to the README.txt included
