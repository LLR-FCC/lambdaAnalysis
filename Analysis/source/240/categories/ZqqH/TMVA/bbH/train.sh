#!/bin/bash
cd /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses
source setup.sh
cd /afs/cern.ch/user/n/niharrin/work/public/MA/FCCeePhysicsPerformance/case-studies/higgs/dataframe
source localSetup.sh
cd /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/categories/ZqqH/TMVA/bbH
root TMVA_bbH_classification.C