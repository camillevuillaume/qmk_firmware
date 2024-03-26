# Added my own keymap. 
On top of personal changes I did in the default layer, I also modified the  mouse layer by adding new keys combinations and a mouse sniper mode (800 DPI instead of 1500 for other layers). 

To use it, do the following:
- Clone the repository 'git clone git@github.com:camillevuillaume/qmk_firmware.git' 
- Update all submodules 'git submodule update --init --recursive'
- Get remote branches 'git fetch origin' 
- Move to branch 'git checkout tarohayashi'
- Compile with 'qmk compile -kb tarohayashi/killerwhale/duo -km camillevuillaume'
- Flash with 'qmk flash -kb tarohayashi/killerwhale/duo -km camillevuillaume'
