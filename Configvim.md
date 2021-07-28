#My_configuration_of_vim
set number
set numberwidth=1
set clipboard=unnamed
syntax enable
set showcmd
set showmatch
set relativenumber
set laststatus=2
set tabstop=8 shiftwidth=8
set autoindent
set smartindent
set cindent
set noshowmode

"call plug#begin('~/.vim/plugged')

"themes
"Plug'morhetz/gruvbox'


"IDE
"Plug'easymotion/vim-easymotion'
"Plug'scrooloose/nerdtree'
"Plug'christoomey/vim-tmux-navigator'

"airline theme
"Plug'vim-airline/vim-airline'
"Plug'vim-airline/vim-airline-themes'

"call plug#end()

colorscheme gruvbox
"let g:gruvbox_contrast_dark = "hard"
"set background=dark
"let NERDTreeQuitOnOpen=1
"let g:airline_theme='virtualenv'

"tecla para iniciar pluggins
let mapleader=" "

"sirve solo en modo normal
nmap <Leader>s <Plug>(easymotion-s2)
nmap <Leader>nt :NERDTreeFind<CR>

"atajos
nmap <Leader>w :w<CR>
nmap <Leader>q :q<CR>
nmap <Leader>e :q!<CR>
