import ROOT

# global parameters
intLumi        = 1.5e+06 #in pb-1
customLabel    = 'e^{+}e^{-} #rightarrow e^{+}e^{-} + H #rightarrow e^{+}e^{-} + bb'
delphesVersion = '3.4.2'
energy         = 365.0
collider       = 'FCC-ee'
inputDir       = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_eebb_exclusive/presel_10/'
formats        = ['png']
yaxis          = ['lin','log']
stacksig       = ['stack','nostack']
outdir         = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_eebb_exclusive/plots/plt_10/'
scaleSig       = 1.0
#ana_tex    = 'M_{Rec} \in [100, 160] GeV, M_{ij} \in [86, 96] GeV'
ana_tex        = ''

#variables = ['mz','mz_zoom', 'm_rec', 'z_pt', 'ht']
#variables = ['m_rec', 'ht', 'htheta', 'hrtheta', 'pT1', 'pT2', 'E1', 'E2', 'Eta1', 'Eta2', 'Acoll_ij', 'Jet_No', 'bJet_No', 'pT_ij', 'mz', 'FinalClassifier_BDT', 'FinalClassifier_DNN', 'FinalClassifier_MLP']
variables = ['m_rec', 'jet_ht', 'htheta', 'hrtheta', 'pT1', 'pT2', 'E1', 'E2', 'Eta1', 'Eta2', 'Acoll_ij', 'Acoll_PaPb', 'Jet_No', 'bJet_No', 'pT_ij', 'M_ij', 'MET', 'MET_Angle', 'pL_ij', 'pL1', 'pL2', 'DeltaEta_ij', 'cJet_No']

###Dictonnary with the analysis name as a key, and the list of selections to be plotted for this analysis. The name of the selections should be the same than in the final selection
selections = {}

#selections['VBF']   = ["sel0", "selVBF_noBDT_NoVetoM", "selVBF_noBDT_VetoM", "selVBF_noBDT_VetoM1", "selVBF_noBDT_VetoM2", "selVBF_noBDT_VetoM3", "selVBF_noBDT_VetoM4", "selVBF_noBDT_VetoM5"]
selections['VBF']   = ["sel0", "selVBF_noBDT_NoVetoM", "selVBF_noBDT_VetoM", "selVBF_noBDT_VetoM1", "selVBF_noBDT_VetoM2", "selVBF_noBDT_VetoM3", "selVBF_noBDT_VetoM4", "selVBF_VetoM", "selVBF_VetoM1", "selVBF_VetoM2", "selVBF_VetoM3", "selVBF_VetoM4", "selVBF_VetoM5"]


#label={}
#label['selZbbFinal3'] = "M_{Rec} \in [100, 160] GeV"

extralabel = {}
#extralabel['selVBF_noBDT'] = "N_{bH} = 2, #||{#Delta #eta} < 3, HT > 20 GeV, MET > 10 GeV"
#extralabel['selVBF'] = "selVBF_noBDT cuts, #beta_{bb} > -0.0589"
#extralabel['selVBF1'] = "selVBF_noBDT cuts, #beta_{bb} > -0.0589, p_{TRec} < 100 GeV"
#extralabel['selVBF2'] = "selVBF_noBDT cuts, #beta_{bb} > -0.0589, p_{TRec} < 90 GeV"
#extralabel['selVBF3'] = "selVBF_noBDT cuts, #beta_{bb} > -0.0589, p_{TRec} < 80 GeV"
#extralabel['selVBF4'] = "selVBF_noBDT cuts, #beta_{bb} > -0.0589, p_{TRec} < 70 GeV"

extralabel['selVBF_noBDT_Veto'] = "N_{bH} = 2, #||{#Delta #eta} < 3, HT > 20 GeV, No e or #mu in FS"
#extralabel['selVBF_noBDT_VetoMu'] = "N_{bH} = 2, #||{#Delta #eta} < 3, HT > 20 GeV, MET > 50 GeV, No #mu in FS"

extralabel['selVBF_noBDT_VetoM'] = "selNoVBF_noBDT_noVetoM cuts, No #mu in FS"
extralabel['selVBF_noBDT_VetoM1'] = "selNoVBF_noBDT_noVetoM cuts, No #mu in FS"
extralabel['selVBF_noBDT_VetoM2'] = "selNoVBF_noBDT_noVetoM cuts, No #mu in FS"
extralabel['selVBF_noBDT_VetoM3'] = "selNoVBF_noBDT_noVetoM cuts, No #mu in FS"
extralabel['selVBF_noBDT_VetoM4'] = "selNoVBF_noBDT_noVetoM cuts, No #mu in FS"
extralabel['selVBF_noBDT_VetoM5'] = "selNoVBF_noBDT_noVetoM cuts, No #mu in FS"
extralabel['selVBF_noBDT_NoVetoM'] = "N_{bH} = 2, #||{#Delta #eta} < 3, HT > 20 GeV"

extralabel['selVBF_Veto'] = "selVBF_noBDT_Veto cuts, #beta_{bb} > -0.2227, No e or #mu in FS"
extralabel['selVBF_VetoM'] = "selVBF_noBDT_VetoM cuts, #beta_{bb} > -0.2227, No #mu in FS"
extralabel['selVBF_VetoM1'] = "selVBF_noBDT_VetoM cuts, #beta_{bb} > -0.2227, No #mu in FS, Acoll > 1.25"
extralabel['selVBF_VetoM2'] = "selVBF_noBDT_VetoM cuts, #beta_{bb} > -0.2227, No #mu in FS, Acoll > 1.25"
extralabel['selVBF_VetoM3'] = "selVBF_noBDT_VetoM cuts, #beta_{bb} > -0.2227, No #mu in FS, Acoll > 1.25"
extralabel['selVBF_VetoM4'] = "selVBF_noBDT_VetoM cuts, #beta_{bb} > -0.2227, No #mu in FS, Acoll > 1.25"
extralabel['selVBF_VetoM5'] = "selVBF_noBDT_VetoM cuts, #beta_{bb} > -0.2227, No #mu in FS, Acoll > 1.25, N_b > 0"
extralabel['selVBF_NoVetoM'] = "selVBF_noBDT_NoVetoM cuts, #beta_{bb} > -0.2227"
extralabel['sel0'] = "No cuts"



colors = {}
colors['VBF'] = ROOT.kRed
colors['WW'] = ROOT.kBlue+1
colors['ZZ'] = ROOT.kGreen+2
colors['VV'] = ROOT.kGreen+3
colors['ZH'] = ROOT.kOrange

plots = {}
plots['VBF'] = {'signal':{'VBF':['wzp6_ee_eeH_ecm365']},
               'backgrounds':{  'WW':['p8_ee_WW_ecm365'],
                                'ZZ':['p8_ee_ZZ_ecm365'],
                                'ZH':['p8_ee_ZH_ecm365']}
           }


plots['ZH_2'] = {'signal':{'VBF':['wzp6_ee_eeH_ecm365']},
                 'backgrounds':{'VV':['p8_ee_WW_ecm365','p8_ee_ZZ_ecm365'], 'ZH':['p8_ee_ZH_ecm365']}
             }

legend = {}
legend['ZH'] = 'ZH'
legend['VBF'] = 'VBF'
legend['WW'] = 'WW'
legend['ZZ'] = 'ZZ'
legend['VV'] = 'VV boson'



