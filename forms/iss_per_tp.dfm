object iss_t_tp: Tiss_t_tp
  Left = 232
  Top = 20
  Width = 525
  Height = 747
  Caption = #1055#1077#1088#1077#1093#1086#1076' '#1074' '#1058#1055
  Color = clBtnFace
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
    Left = 8
    Top = 584
    Width = 83
    Height = 13
    Caption = #1042#1088#1077#1084#1103' '#1087#1077#1088#1077#1093#1086#1076#1072
  end
  object Label2: TLabel
    Left = 8
    Top = 600
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label9: TLabel
    Left = 104
    Top = 608
    Width = 8
    Height = 13
    Caption = 'w'
  end
  object Label10: TLabel
    Left = 98
    Top = 632
    Width = 14
    Height = 13
    Caption = 'dw'
  end
  object Chart1: TChart
    Left = 0
    Top = 0
    Width = 509
    Height = 289
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    MarginLeft = 0
    Title.Alignment = taLeftJustify
    Title.Font.Charset = RUSSIAN_CHARSET
    Title.Font.Color = clBlue
    Title.Font.Height = -11
    Title.Font.Name = 'Arial Narrow'
    Title.Font.Style = [fsBold, fsItalic]
    Title.Text.Strings = (
      'W, '#1075#1088'./'#1089#1077#1082)
    BottomAxis.LabelStyle = talText
    LeftAxis.Axis.Visible = False
    LeftAxis.Ticks.Style = psDot
    Legend.Visible = False
    RightAxis.Visible = False
    TopAxis.Visible = False
    View3D = False
    View3DWalls = False
    Align = alTop
    BevelOuter = bvNone
    Color = clAqua
    TabOrder = 0
    object Series1: TFastLineSeries
      Marks.ArrowLength = 8
      Marks.BackColor = clAqua
      Marks.Clip = True
      Marks.Frame.Visible = False
      Marks.Style = smsXValue
      Marks.Visible = True
      SeriesColor = -1
      LinePen.Color = -1
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object GroupBox1: TGroupBox
    Left = 120
    Top = 592
    Width = 105
    Height = 65
    Caption = ' '#1050#1088#1077#1085' '
    TabOrder = 1
    object Label3: TLabel
      Left = 40
      Top = 18
      Width = 51
      Height = 13
      Caption = '0.0000000'
    end
    object Label4: TLabel
      Left = 40
      Top = 41
      Width = 51
      Height = 13
      Caption = '0.0000000'
    end
    object Panel1: TPanel
      Left = 8
      Top = 16
      Width = 14
      Height = 14
      BevelOuter = bvNone
      Color = clGreen
      TabOrder = 0
    end
    object Panel2: TPanel
      Left = 8
      Top = 40
      Width = 14
      Height = 14
      BevelOuter = bvNone
      Color = clGreen
      TabOrder = 1
    end
  end
  object GroupBox2: TGroupBox
    Left = 232
    Top = 592
    Width = 105
    Height = 65
    Caption = ' '#1056#1099#1089#1082#1072#1085#1080#1077' '
    TabOrder = 2
    object Label5: TLabel
      Left = 40
      Top = 18
      Width = 51
      Height = 13
      Caption = '0.0000000'
    end
    object Label6: TLabel
      Left = 40
      Top = 41
      Width = 51
      Height = 13
      Caption = '0.0000000'
    end
    object Panel3: TPanel
      Left = 8
      Top = 16
      Width = 14
      Height = 14
      BevelOuter = bvNone
      Color = clNavy
      TabOrder = 0
    end
    object Panel4: TPanel
      Left = 8
      Top = 40
      Width = 14
      Height = 14
      BevelOuter = bvNone
      Color = clNavy
      TabOrder = 1
    end
  end
  object GroupBox3: TGroupBox
    Left = 344
    Top = 592
    Width = 105
    Height = 65
    Caption = ' '#1058#1072#1085#1075#1072#1078' '
    TabOrder = 3
    object Label7: TLabel
      Left = 40
      Top = 18
      Width = 51
      Height = 13
      Caption = '0.0000000'
    end
    object Label8: TLabel
      Left = 40
      Top = 41
      Width = 51
      Height = 13
      Caption = '0.0000000'
    end
    object Panel5: TPanel
      Left = 8
      Top = 16
      Width = 14
      Height = 14
      BevelOuter = bvNone
      Color = clMaroon
      TabOrder = 0
    end
    object Panel6: TPanel
      Left = 8
      Top = 40
      Width = 14
      Height = 14
      BevelOuter = bvNone
      Color = clMaroon
      TabOrder = 1
    end
  end
  object Button1: TButton
    Left = 8
    Top = 680
    Width = 75
    Height = 25
    Caption = #1057#1090#1086#1087
    TabOrder = 4
  end
  object Chart2: TChart
    Left = 0
    Top = 289
    Width = 509
    Height = 289
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    MarginLeft = 0
    Title.Alignment = taLeftJustify
    Title.Font.Charset = RUSSIAN_CHARSET
    Title.Font.Color = clBlue
    Title.Font.Height = -11
    Title.Font.Name = 'Arial Narrow'
    Title.Font.Style = [fsBold, fsItalic]
    Title.Text.Strings = (
      #1060', '#1075#1088'.')
    BottomAxis.LabelStyle = talText
    LeftAxis.Axis.Visible = False
    LeftAxis.Ticks.Style = psDot
    Legend.Visible = False
    RightAxis.Visible = False
    TopAxis.Visible = False
    View3D = False
    View3DWalls = False
    Align = alTop
    BevelOuter = bvNone
    Color = clAqua
    TabOrder = 5
    object FastLineSeries1: TFastLineSeries
      Marks.ArrowLength = 8
      Marks.BackColor = clAqua
      Marks.Clip = True
      Marks.Frame.Visible = False
      Marks.Style = smsXValue
      Marks.Visible = True
      SeriesColor = -1
      LinePen.Color = -1
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object Timer1: TTimer
    Enabled = False
    Left = 472
    Top = 672
  end
end
