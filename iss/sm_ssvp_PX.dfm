object sm_ssvp_plx_frm: Tsm_ssvp_plx_frm
  Left = 875
  Top = 131
  Width = 409
  Height = 398
  Caption = #1057#1052':'#1057#1057#1042#1055':+'#1061
  Color = clAppWorkSpace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 152
    Top = 0
    Width = 81
    Height = 20
    Caption = #1057#1052':'#1057#1057#1042#1055':+'#1061
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial Narrow'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 32
    Width = 87
    Height = 16
    Caption = #1056#1077#1078#1080#1084' '#1086#1090' '#1041#1042#1057
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object bvs_mode: TLabel
    Left = 104
    Top = 32
    Width = 121
    Height = 16
    AutoSize = False
    Color = clWhite
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 56
    Width = 38
    Height = 16
    Caption = #1050#1088#1102#1082#1080
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object kruki: TLabel
    Left = 56
    Top = 56
    Width = 121
    Height = 16
    AutoSize = False
    Color = clWhite
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label6: TLabel
    Left = 8
    Top = 80
    Width = 81
    Height = 16
    Caption = #1059#1087#1086#1088#1099' '#1075#1085#1077#1079#1076#1072
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object upor: TLabel
    Left = 96
    Top = 80
    Width = 121
    Height = 16
    AutoSize = False
    Color = clWhite
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label8: TLabel
    Left = 8
    Top = 104
    Width = 70
    Height = 16
    Caption = #1050#1088#1099#1096#1082#1072' '#1087'/'#1083
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object kr_p1: TLabel
    Left = 88
    Top = 104
    Width = 81
    Height = 16
    AutoSize = False
    Color = clWhite
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object kr_p2: TLabel
    Left = 176
    Top = 104
    Width = 129
    Height = 16
    AutoSize = False
    Color = clWhite
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object SpeedButton1: TSpeedButton
    Left = 360
    Top = 96
    Width = 25
    Height = 25
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 128
    Width = 185
    Height = 225
    Caption = ' '#1050#1086#1084#1072#1085#1076#1099' '
    TabOrder = 0
    object ListBox1: TListBox
      Left = 8
      Top = 16
      Width = 169
      Height = 129
      Color = clAqua
      ItemHeight = 13
      Items.Strings = (
        'N_ONSSVP1'
        'N_ONSSVP2'
        'N_OFSSVP'
        'N_OPKR N_CLKR'
        'N_OPUG N_CLUG'
        'N_OPPL N_CLPL'
        'D_SSTADWX'
        'D_SSTADWY'
        'D_SSTAUPY'
        'D_SSTAUPX')
      TabOrder = 0
    end
  end
  object GroupBox2: TGroupBox
    Left = 200
    Top = 128
    Width = 185
    Height = 225
    Caption = ' '#1055#1088#1086#1094#1077#1076#1091#1088#1099' '
    TabOrder = 1
    object Label11: TLabel
      Left = 8
      Top = 208
      Width = 33
      Height = 13
      Caption = 'Status:'
    end
    object ListBox2: TListBox
      Left = 8
      Top = 16
      Width = 169
      Height = 129
      Color = clAqua
      ItemHeight = 13
      Items.Strings = (
        'F13_OUG1_0'
        'F13_OUG2_1'
        'F13_OUG3_2'
        'F13_OUG4_3'
        'F13_ZUG1_4'
        'F13_ZUG2_5'
        'F13_ZUG3_6'
        'F13_ZUG4_7'
        'F13_OKR1_8'
        'F13_OKR2_9')
      TabOrder = 0
    end
    object Button1: TButton
      Left = 8
      Top = 168
      Width = 49
      Height = 17
      Cursor = crHandPoint
      Caption = #1047#1072#1087#1091#1089#1082
      TabOrder = 1
    end
  end
  object il: TImageList
    Left = 360
    Top = 8
    Bitmap = {
      494C010102000400040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000040000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000004000000040000000400000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000004000000040000000400000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000004000000040000000400000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000400000004000000040000000400000004000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000004000000040000000400000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000040000000400000004000000040000000400000004000000040000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000004000000040000000400000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000400
      0000040000000400000004000000040000000400000004000000040000000400
      0000000000000000000000000000000000000000000000000000000000000400
      0000040000000400000004000000040000000400000004000000040000000400
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000004000000040000000400000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000040000000400000004000000040000000400000004000000040000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000004000000040000000400000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000400000004000000040000000400000004000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000004000000040000000400000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000004000000040000000400000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000004000000040000000400000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000040000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFF00000000FFFFFFFF00000000
      FFFFFFFF00000000FFFFFFFF00000000FEFFFC7F00000000FC7FFC7F00000000
      F83FFC7F00000000F01FFC7F00000000E00FE00F00000000FC7FF01F00000000
      FC7FF83F00000000FC7FFC7F00000000FC7FFEFF00000000FFFFFFFF00000000
      FFFFFFFF00000000FFFFFFFF0000000000000000000000000000000000000000
      000000000000}
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 360
    Top = 40
  end
end