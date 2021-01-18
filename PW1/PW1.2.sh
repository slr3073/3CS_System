# Show my process
ps

# We search how to select all process in ps manual
man ps

# By using / bind and researching the keyword "file" we find out that -e showcase all process and -f show full format
# Show all process
ps -ef

# Because it is a long result we can pipe it into more
ps -ef | more

# We want to format the ps format so that is only shows pid, ppid, user and the command
ps -eo pid,ppid,euser,args | more

# We want to showcase the process tree there are two ways to do it :
pstree
# Using ps we can fix all parameters
ps -efH | more
ps -eo pid,ppid,euser,args -H | more