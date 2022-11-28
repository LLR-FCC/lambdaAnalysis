#!/bin/bash
cd /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses
source setup.sh
cd /afs/cern.ch/user/n/niharrin/work/public/MA/FCCeePhysicsPerformance/case-studies/higgs/dataframe
source localSetup.sh
cd /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/categories/ZqqH/TMVA/ijH
root TMVA_ijH_classification.C