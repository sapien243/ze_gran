## install-scoop-apps.ps1
## this script installs apps using scoop

# define list of applications to install
$apps = @(
	"main/clink"
	"main/git"
	"main/git-lfs"
	"main/helix"
	"java/liberica-jre"
	"versions/mingw-winlibs-llvm-ucrt"
	"extras/musicbee"
	"main/neovim"
	"main/php"
	"main/psutils"
	"versions/python312"
	"main/racket"
	"extras/rufus"
	"main/sqlite"
	"main/starship"
	"extras/sublime-merge"
	"extras/ventoy"
	"extras/zed"
	"main/zig"
	"main/zls"
)

# install scoop
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
irm get.scoop.sh -outfile 'install.ps1'
.\install.ps1 -ScoopDir 'C:\Scoop' -NoProxy

# setting up scoop buckets
scoop bucket add main
scoop bucket add java
scoop bucket add versions
scoop bucket add extras
scoop update

# loop through each application and install it
foreach ($app in $apps) {
	scoop install $app
}