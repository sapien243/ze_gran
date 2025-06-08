## install-winget-apps.ps1
## this script installs apps using winget

# define list of applications to install
$apps = @(
	"7zip.7zip"
	"Brave.Brave"
	"Klocman.BulkCrapUninstaller"
	"Mozilla.Firefox"
	"KiCad.KiCad"
	"KDE.Krita"
	"logisim-evolution.logisim-evolution"
	"Logseq.Logseq"
	"Notepad++.Notepad++"
	"OBSProject.OBSStudio"
	"KDE.Okular"
	"qBittorrent.qBittorrent"
	"Scribus.Scribus"
	"Spotify.Spotify"
	"Stellarium.Stellarium"
	"VideoLAN.VLC"
	"WiresharkFoundation.Wireshark"

	"Recoupler.AudioBookConverter"
	"BlenderFoundation.Blender"
	"darktable.darktable"
	"Eassos.DiskGenius"
	"ente-io.auth-desktop"
	"GIMP.GIMP"
	"NDI.NDITools"
	"WhatsApp.WhatsApp"
	"Windscribe.Windscribe"

	"Microsoft.DirectX"
	"Microsoft.DotNet.Runtime.6"
	"Microsoft.DotNet.Runtime.8"
	"Microsoft.VCRedist.2015+.x64"
	"Microsoft.VCRedist.2015+.x86"
	"Microsoft.VCRedist.2013.x64"
	"Microsoft.VCRedist.2013.x86"
	"Microsoft.VCRedist.2012.x64"
	"Microsoft.VCRedist.2012.x86"
	"Microsoft.VCRedist.2010.x64"
	"Microsoft.VCRedist.2010.x86"
	"Microsoft.VCRedist.2008.x64"
	"Microsoft.VCRedist.2008.x86"
	"Microsoft.VCRedist.2005.x64"
	"Microsoft.VCRedist.2005.x86"
)

# set up winget
Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scope Process
wsreset -i
Add-AppxPackage -RegisterByFamilyName -MainPackage Microsoft.DesktopAppInstaller_8wekyb3d8bbwe
# Or ~> Add-AppxPackage https://github.com/microsoft/winget-cli/releases/latest/download/Microsoft.DesktopAppInstaller_8wekyb3d8bbwe.msixbundle

# loop through each application and install it
foreach ($app in $apps) {
	$location = "C:\winget\" + $app.Replace(".","-")
	winget install -e -i --id $app --location $location
}