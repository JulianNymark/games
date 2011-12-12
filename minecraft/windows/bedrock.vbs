Dim WshShell

Set WshShell = WScript.CreateObject ("WScript.Shell")
WshShell.Run "cmd /K pressEsc.o & exit", 1, true
For IntMyInteger = 1 To 15
	WshShell.Run "cmd /K giveItem.o 7 64 & exit", 1, true
	Next
set WshShell = nothing