object ssvp_frm: Tssvp_frm
  Left = 357
  Top = 156
  Width = 463
  Height = 540
  Caption = #1057#1057#1042#1055' - '#1055#1088#1086#1094#1077#1089#1089' '#1089#1090#1099#1082#1086#1074#1082#1080' - '#1055#1088#1086#1094#1077#1089#1089#1091#1072#1083#1100#1085#1072#1103
  Color = clInactiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 44
    Top = 426
    Width = 20
    Height = 22
    Caption = '0-'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Consolas'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object Label2: TLabel
    Left = 24
    Top = 328
    Width = 40
    Height = 22
    Caption = '100-'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Consolas'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object Label3: TLabel
    Left = 24
    Top = 229
    Width = 40
    Height = 22
    Caption = '200-'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Consolas'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object Label4: TLabel
    Left = 24
    Top = 130
    Width = 40
    Height = 22
    Caption = '300-'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Consolas'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object Label5: TLabel
    Left = 24
    Top = 32
    Width = 40
    Height = 22
    Caption = '400-'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Consolas'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object Label6: TLabel
    Left = 11
    Top = 8
    Width = 130
    Height = 20
    Caption = #1061#1086#1076' '#1096#1090#1072#1085#1075#1080' '#1057#1059
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object s_pos: TLabel
    Left = 92
    Top = 426
    Width = 20
    Height = 22
    Caption = '-'#1061
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Consolas'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object xod_sh: TProgressBar
    Left = 64
    Top = 36
    Width = 25
    Height = 404
    Min = 0
    Max = 404
    Orientation = pbVertical
    Smooth = True
    Step = 1
    TabOrder = 0
  end
  object test_btn: TButton
    Left = 216
    Top = 8
    Width = 75
    Height = 25
    Caption = 'test_btn'
    TabOrder = 1
    OnClick = test_btnClick
  end
  object Panel1: TPanel
    Left = 144
    Top = 80
    Width = 273
    Height = 217
    TabOrder = 2
    object ssvp_pas: TPaintBox
      Left = 16
      Top = 8
      Width = 121
      Height = 201
      Color = clBackground
      ParentColor = False
    end
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 168
    Top = 8
  end
end
