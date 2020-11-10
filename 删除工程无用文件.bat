echo off
:s1
for /d %%i in (.\) do (cd %%i
	del /s *.mdp
	del /s *.clw
	del /s *.cpl
	del /s *.awk
	del /s *.map
	del /s *.scc
	del /s *.tlb
	del /s *.ncb
	del /s *.opt
	del /s *.plg
	del /s *.aps
	del /s *.idb
	del /s *.pch
	del /s *.sbr
	del /s *.obj
	del /s *.ilk
	del /s *.bsc
	del /s *.fd
	del /s *.bak
	del /s *.tlh
	del /s *.tli
	del /s *.pdb
	del /s *.exp
	del /s *.positions
	del /s *.sdf
	del /s *.tlog
	del /s *.log
	del /s *.ipdb
	del /s *.iobj
	rem	del /s *.res
rem 下面是准备删除【debug】和【release】文件夹的内容，但谨慎删除！！
rem rd /s/q debug
rem rd /s/q release
cd ..)

:end
pause