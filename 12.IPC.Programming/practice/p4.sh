# Make named pipe np.
mkfifo np
# 
ls -al > np
#
cat < np
