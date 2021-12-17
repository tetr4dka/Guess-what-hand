; ��� ����������
#define   Name       "GuessWhatHand"
; ������ ����������
#define   Version    "1.0.0"
; �����-�����������
#define   Publisher  "Aleksei Faleev"
; ���� ����� �������������
#define   URL        "http://www.vk.com/mishklgpmi"
; ��� ������������ ������
#define   ExeName    "GuessWhatHand.exe"

;------------------------------------------------------------------------------
;   ��������� ���������
;------------------------------------------------------------------------------
[Setup]

; ���������� ������������� ����������, 
;��������������� ����� Tools -> Generate GUID
AppId={{A853DCE8-5B08-4C79-B573-F7A802ED0797}

; ������ ����������, ������������ ��� ���������
AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppPublisherURL={#URL}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

; ���� ��������� ��-���������
DefaultDirName={pf}\{#Name}
; ��� ������ � ���� "����"
DefaultGroupName={#Name}

; �������, ���� ����� ������� ��������� setup � ��� ������������ �����
OutputDir=C:\Git\setup_
OutputBaseFileName=GuessWhatHand

; ���� ������
SetupIconFile=C:\Git\Guess what hand\img\coin.ico

; ��������� ������
Compression=lzma
SolidCompression=yes

;------------------------------------------------------------------------------
;   ������������� ����� ��� �������� ���������
;------------------------------------------------------------------------------
[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"; LicenseFile: "License_ENG.txt"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: "License_RUS.txt"

;------------------------------------------------------------------------------
;   ����������� - ��������� ������, ������� ���� ��������� ��� ���������
;------------------------------------------------------------------------------
[Tasks]
; �������� ������ �� ������� �����
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

;------------------------------------------------------------------------------
;   �����, ������� ���� �������� � ����� �����������
;------------------------------------------------------------------------------
[Files]

; ����������� ����
Source: "C:\Build\Guess what hand\Release\GuessWhatHand.exe"; DestDir: "{app}"; Flags: ignoreversion

; ������������� �������
Source: "C:\Git\Guess what hand\img\*"; DestDir: "{app}\img\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Git\Guess what hand\fonts\*"; DestDir: "{app}\fonts\"; Flags: ignoreversion recursesubdirs createallsubdirs

; VS Redistributable package
Source: "C:\Git\Installer\VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall
;------------------------------------------------------------------------------
;   ��������� �����������, ��� �� ������ ����� ������
;------------------------------------------------------------------------------ 
[Icons]

Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"

Name: "{commondesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; Tasks: desktopicon

[Run]
;------------------------------------------------------------------------------
;   ��������� ����������������� ������ VS
;------------------------------------------------------------------------------
Filename: {tmp}\VC_redist.x64.exe; Parameters: "/q:a /c:""install /l /q"""; StatusMsg: VS redistributable package is installed. Please wait...
