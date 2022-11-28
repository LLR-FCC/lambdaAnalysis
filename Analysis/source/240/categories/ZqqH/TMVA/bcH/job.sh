universe                = vanilla
executable              = train.sh
arguments               = 
log                     = train.log
output                  = outfile.$(Cluster).$(Process).out
error                   = errors.$(Cluster).$(Process).err
should_transfer_files   = NO
+JobFlavour = "workday"
#espresso     = 20 minutes
#microcentury = 1 hour
#longlunch    = 2 hours
#workday      = 8 hours
#tomorrow     = 1 day
#testmatch    = 3 days
#nextweek     = 1 week
requestCpus = 8
queue