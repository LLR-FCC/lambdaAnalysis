import ROOT

# global parameters
intLumi        = 5.0e+06 #in pb-1
#customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow bb + X'
#customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow jb + X'
customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow ij + X'
#customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow cc + X'
#customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow jc + X'
delphesVersion = '3.4.2'
energy         = 240.0
collider       = 'FCC-ee'
inputDir       = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_bbH_inclusive/240/presel_10/'
formats        = ['png']
yaxis          = ['lin','log']
stacksig       = ['stack','nostack']
outdir         = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_bbH_inclusive/240/TMVA/jjH/plots/'
scaleSig       = 1.0
#ana_tex    = 'M_{Rec} \in [100, 160] GeV, M_{ij} \in [86, 96] GeV'
ana_tex        = ''

#variables = ['mz','mz_zoom', 'm_rec', 'z_pt', 'ht']
#variables = ['m_rec', 'ht', 'htheta', 'hrtheta', 'pT1', 'pT2', 'E1', 'E2', 'Eta1', 'Eta2', 'Acoll_ij', 'Jet_No', 'bJet_No', 'pT_ij', 'mz', 'FinalClassifier_BDT', 'FinalClassifier_DNN', 'FinalClassifier_MLP']
variables = ['m_rec', 'jet_ht', 'htheta', 'hrtheta', 'pT1', 'pT2', 'E1', 'E2', 'Eta1', 'Eta2', 'Acoll_ij', 'Jet_No', 'bJet_No', 'pT_ij', 'M_ij', 'zed_bJet_No', 'zed_cJet_No', 'zed_lJet_No', 'MET', 'MET_Angle', 'FinalClassifier_BDT_jj']
###Dictonnary with the analysis name as a key, and the list of selections to be plotted for this analysis. The name of the selections should be the same than in the final selection
selections = {}
#selections['ZH']   = ["sel0", "sel1", "sel2", "sel6", "sel7", "sel8", "sel9", "sel10", "sel11", "sel13"]
#selections['ZH']   = ["sel0", "sel1", "sel2", "sel6", "sel7", "selZbbFinal", "selZbbFinal2", "selZbbFinal3_0", "selZbbFinal3", "selZjbFinal", "selZjbFinal2", "selZjbFinal3", "selZjjFinal", "selZjjFinal2", "selZjjFinal3", "selZccFinal", "selZccFinal2", "selZccFinal3"]
#selections['ZH']   = ["selZbbFinal", "selZbbFinal2", "selZbbFinal3_0", "selZbbFinal3"]
#selections['ZH']   = ["selZjbFinal", "selZjbFinal2", "selZjbFinal3", "selZjbFinal4", "selZjbFinal5", "selZjbFinal6", "selZjbFinal7", "selZjbFinal8", "selZjbFinal9", "selZjbFinal10", "selZjbFinal11", "selZjbFinal12", "selZjbFinal13", "selZjbFinal14", "selZjbFinal15"]
#selections['ZH']   = ["selZjjFinal", "selZjjFinal2", "selZjjFinal3", "selZjjFinal4", "selZjjFinal5", "selZjjFinal6", "selZjjFinal7", "selZjjFinal8"]

selections['ZH']   = ["selZjjFinal_noBDT", "selZjjFinal", "selZjjFinal2"]
#selections['ZH']   = ["selZjjFinal_noBDT"]

#selections['ZH']   = ["selZccFinal", "selZccFinal2", "selZccFinal3", "selZccFinal0"]
#selections['ZH']   = ["selZjcFinal", "selZjcFinal2", "selZjcFinal3"]
#selections['ZH_2'] = ["sel0", "sel1", "sel2", "sel3", "sel4", "sel5", "sel6"]

#label={}
#label['selZbbFinal3'] = "M_{Rec} \in [100, 160] GeV"

extralabel = {}
extralabel['selZjjFinal_noBDT'] = "N_{bZ} = 0, M_{Rec} #in #[]{100, 160} GeV, M_{ij} #in #[]{86, 96} GeV"
extralabel['selZjjFinal'] = "selZjjFinal_noBDT cuts, #beta_{jj} > 0.2895"
extralabel['selZjjFinal2'] = "selZjjFinal_noBDT cuts, #beta_{jj} > 0.2895, N_{bJets} > 1"
#extralabel['selZjjFinal3'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jj} > -0.09"
#extralabel['selZjjFinal4'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jj} > -0.09"
#extralabel['selZjjFinal5'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jj} > -0.09"
#extralabel['selZjjFinal6'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jj} > -0.09"
#extralabel['selZjjFinal7'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jj} > -0.09"
#extralabel['selZjjFinal8'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jj} > -0.09"
#extralabel['selZjjFinal8'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZjjFinal9'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZjjFinal10'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZjjFinal11'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZjjFinal12'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZjjFinal13'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZjjFinal14'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZjjFinal15'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"






colors = {}
colors['ZH'] = ROOT.kRed
colors['WW'] = ROOT.kBlue+1
colors['ZZ'] = ROOT.kGreen+2
colors['VV'] = ROOT.kGreen+3
colors['Zqq'] = ROOT.kOrange+2

plots = {}
plots['ZH'] = {'signal':{'ZH':['wzp6_ee_qqH_ecm240']},
               'backgrounds':{'WW':['p8_ee_WW_ecm240'],
                              'ZZ':['p8_ee_ZZ_ecm240'],
                              'Zqq':['p8_ee_Zqq_ecm240']}
           }


plots['ZH_2'] = {'signal':{'ZH':['wzp6_ee_qqH_ecm240']},
                 'backgrounds':{'VV':['p8_ee_WW_ecm240','p8_ee_ZZ_ecm240'],
                                'Zqq':['p8_ee_Zqq_ecm240']}
             }

legend = {}
legend['ZH'] = 'ZH'
legend['WW'] = 'WW'
legend['ZZ'] = 'ZZ'
legend['VV'] = 'VV boson'
legend['Zqq'] = 'Zqq'



