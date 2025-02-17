#
# Regular cron jobs for the laba1spo package.
#
0 4	* * *	root	[ -x /usr/bin/laba1spo_maintenance ] && /usr/bin/laba1spo_maintenance
