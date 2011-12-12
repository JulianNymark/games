Dim WshShell

Set WshShell = WScript.CreateObject ("WScript.Shell")
WshShell.Run "cmd /K pressEsc.o & exit", 1, true
WshShell.Run "cmd /K giveItem.o 276 1 & exit", 1, true
WshShell.Run "cmd /K giveItem.o 277 1 & exit", 1, true
WshShell.Run "cmd /K giveItem.o 278 1 & exit", 1, true
WshShell.Run "cmd /K giveItem.o 279 1 & exit", 1, true
set WshShell = nothing