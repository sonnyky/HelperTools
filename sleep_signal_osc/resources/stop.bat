rem �A�g���N�V�����I���R�}���h���L�q���Ă�������
setlocal

set "ProcessID="
FOR /F "tokens=2" %%A IN ('tasklist ^| findstr /i "sleep_signal_osc"') DO start .\sendsignal.exe %%A
