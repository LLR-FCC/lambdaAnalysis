import ROOT

# global parameters
intLumi        = 5.0e+06 #in pb-1
ana_tex        = 'e^{+}e^{-} #rightarrow ZH #rightarrow cc + X'
delphesVersion = '3.4.2'
energy         = 240.0
collider       = 'FCC-ee'
inputDir       = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_ccH_inclusive/240/presel/'
formats        = ['png']
yaxis          = ['lin','log']
stacksig       = ['stack','nostack']
outdir         = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_ccH_inclusive/240/plots/'
scaleSig       = 1.0

#variables = ['mz','mz_zoom', 'm_rec', 'z_pt', 'ht']
variables = ['m_rec', 'm_rec_zoom', 'ht', 'htheta', 'hrtheta']

###Dictonnary with the analysis name as a key, and the list of selections to be plotted for this analysis. The name of the selections should be the same than in the final selection
selections = {}
selections['ZH']   = ["sel0", "sel1", "sel2", "sel3", "sel4", "sel5", "sel6"]
selections['ZH_2'] = ["sel0", "sel1", "sel2", "sel3", "sel4", "sel5", "sel6"]

extralabel = {}
extralabel['sel0'] = "Selection: n_c > 1"
extralabel['sel1'] = "Selection: n_c > 1, M_{jj} > 45 GeV"
extralabel['sel2'] = "Selection: n_c > 1, M_{jj} > 45 GeV, pT_{jj} > 35 GeV"
extralabel['sel3'] = "Selection: n_c > 1, M_{jj} > 45 GeV, pT_{jj} > 45 GeV"
extralabel['sel4'] = "Selection: n_c > 1, M_{jj} > 45 GeV, pT_{jj} > 45 GeV, pTRecoil > 45 GeV, HT > 20 GeV"
extralabel['sel5'] = "Selection: n_c > 1, M_{jj} > 45 GeV, pT_{jj} > 45 GeV, pTRecoil > 45 GeV, HT > 20 GeV, \theta > 0.5, \theta < 3.0"
extralabel['sel6'] = "Selection: n_c > 1, M_{jj} > 45 GeV, pT_{jj} > 45 GeV, pTRecoil > 45 GeV, HT > 20 GeV, \theta > 0.8, \theta < 2.3"
#extralabel['sel4'] = "Selection: N_{Z} = 1; 86 GeV < m_{Z} < 96 GeV; 120 GeV < M_{Recoil} < 140 GeV; 20 GeV < p_{T} < 70 GeV; abs(cos_{\theta}) < 0.98"
#extralabel['sel5'] = "Selection: N_{Z} = 1; 86 GeV < m_{Z} < 96 GeV; 122 GeV < M_{Recoil} < 135 GeV; 20 GeV < p_{T} < 70 GeV; abs(cos_{\theta}) < 0.98"

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



