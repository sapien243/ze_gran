# ==== Add to the {HOME}/.bashrc file ==== #

# .git-prompt.sh from https://github.com/git/git/blob/master/contrib/completion/git-prompt.sh
source "${HOME}/.git-prompt.sh"

update() {
  # red="\[\e[91m\]", grn="\[\e[92m\]", mgt="\[\e[95m\]",
  # cyn="\[\e[96m\]", bld="\[\e[1m\]", nrm="\[\e[0m\]"
  PS1="\[\e[1m\]\[\e[91m\]bash \[\e[92m\]\u@\h \[\e[96m\]{\W} \[\e[95m\]$(__git_ps1 ":%s:")\n \[\e[96m\]>> \[\e[0m\]"
}
shopt -u promptvars
PROMPT_COMMAND=update

export HISTCONTROL=ignoreboth:erasedups

# ====

