rem アトラクション終了コマンドを記述してください
setlocal

set "ProcessID="
FOR /F "tokens=2" %%A IN ('tasklist ^| findstr /i "sleep_signal_osc"') DO start .\sendsignal.exe %%A
