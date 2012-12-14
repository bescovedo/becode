# exports
export EDITOR='vim'

# aliases
alias irc='screen irssi'
alias rm='rm -i'
alias trash='trash-put'
alias rtrash='restore-trash'
alias etrash='trash-empty'
alias ltrash='trash-list'
alias nano='nano -x -c -m'
# functions
#function int-ip { /sbin/ifconfig $1 | grep "inet addr" | awk -F: '{print $2}' | awk '{print $1}'; }

# number of lines kept in history
export HISTSIZE=1000
export SAVEHIST=1000
export HISTFILE=~/.zsh_history
setopt inc_append_history

# color directorys / files
alias ls='ls --color=auto'
alias grep='grep --color=auto'

# zsh specific colors
autoload -U colors && colors

# command completion
autoload -U compinit
compinit

# prompt
PROMPT="%B%{$fg[green]%}%n@%m%{$reset_color%}%b %{$fg[yellow]%}%1~ %{$reset_color%}%B%{$fg[blue]%}%#%{$reset_color%}%b "
#RPROMPT="[%{$fg[yellow]%}%T%{$reset_color%}]"

# zsh stuff
zstyle ':completion:*' menu select
