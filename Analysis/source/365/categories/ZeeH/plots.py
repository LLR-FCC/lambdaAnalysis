import ROOT

# global parameters
intLumi        = 1.5e+06 #in pb-1
customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow e^{+}e^{-} + X'
delphesVersion = '3.4.2'
energy         = 365.0
collider       = 'FCC-ee'
inputDir       = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/histos/'
formats        = ['png']
yaxis          = ['lin','log']
stacksig       = ['stack','nostack']
outdir         = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/categories/ZeeH/plots/'
ana_tex        = ''

variables = ['mz','mz_zoom','leptonic_recoil_m','leptonic_recoil_m_zoom','leptonic_recoil_m_zoom2', 'leptonic_pt', 'MET_costheta']

###Dictonnary with the analysis name as a key, and the list of selections to be plotted for this analysis. The name of the selections should be the same than in the final selection
selections = {}
selections['ZH']   = ["sel_ZeeH"]
selections['ZH_2'] = ["sel_ZeeH"]

extralabel = {}
extralabel['sel1'] = "N_{Z} = 1, M_{Tij} #in #[]{86, 96} GeV"
extralabel['sel2'] = "N_{Z} = 1, M_{Tij} #in #[]{86, 96} GeV, M_{Rec} #in #[]{120, 140} GeV"
#Immer N_{Z} = 1, #splitline{M_{Tij} #in #[]{86, 96} GeV}{M_{Rec} #in #[]{120, 140} GeV}
extralabel['sel3'] = "p_{Tij} #in #[]{20, 70} GeV"
extralabel['sel4'] = "p_{Tij} #in #[]{20, 70} GeV, #||{cos(#theta_{Miss})} < 0.98"
#extralabel['sel_noBDT_ZeeH'] = "M_{Rec} #in #[]{122, 135} GeV, p_{Tij} #in #[]{20, 70} GeV, #||{cos(#theta_{Miss})} < 0.98"
extralabel['sel_ZeeH'] = "M_{Rec} #in #[]{120, 140} GeV, #||{cos(#theta_{Miss})} < 0.98"


colors = {}
colors['ZH'] = ROOT.kRed
#colors['WW'] = ROOT.kBlue+1
colors['ZZ'] = ROOT.kGreen+2
colors['VV'] = ROOT.kGreen+3
colors['ee'] = ROOT.kOrange
colors['ll'] = ROOT.kOrange+3

plots = {}
#plots['ZH'] = {'signal':{'ZH':['wzp6_ee_eeH_ecm365', 'p8_ee_ZH_ecm365']},
#               'backgrounds':{'WW':['p8_ee_WW_ecm365'],
#                              'ZZ':['p8_ee_ZZ_ecm365'],
#                              'ee':['wzp6_ee_ee_Mee_30_150_ecm365']}
#           }

plots['ZH'] = {'signal':{'ZH':['wzp6_ee_eeH_ecm365', 'p8_ee_ZH_ecm365']},
               'backgrounds':{'ZZ':['p8_ee_ZZ_ecm365'],
                              'ee':['wzp6_ee_ee_Mee_30_150_ecm365']}
           }


#plots['ZH_2'] = {'signal':{'ZH':['wzp6_ee_eeH_ecm365', 'p8_ee_ZH_ecm365']},
#                 'backgrounds':{'VV':['p8_ee_WW_ecm365','p8_ee_ZZ_ecm365'],
#                                'll':['wzp6_ee_ee_Mee_30_150_ecm365']}
#             }

plots['ZH_2'] = {'signal':{'ZH':['wzp6_ee_eeH_ecm365', 'p8_ee_ZH_ecm365']},
                 'backgrounds':{'VV':['p8_ee_ZZ_ecm365'],
                                'll':['wzp6_ee_ee_Mee_30_150_ecm365']}
             }

legend = {}
legend['ZH'] = 'ZH'
#legend['WW'] = 'WW'
legend['ZZ'] = 'ZZ'
legend['VV'] = 'VV boson'
legend['ee'] = 'Z #rightarrow e^{+}e^{-}'
legend['ll'] = 'Z #rightarrow l^{+}l^{-}'



