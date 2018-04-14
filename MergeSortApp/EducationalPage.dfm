object fEducationalPage: TfEducationalPage
  Left = 1126
  Top = 159
  Width = 631
  Height = 615
  Caption = 'Educational Page'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object lComparisonsAmount: TLabel
    Left = 368
    Top = 144
    Width = 9
    Height = 20
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lComparisonsName: TLabel
    Left = 248
    Top = 144
    Width = 104
    Height = 20
    Caption = 'Comparisons:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lArrAccessName: TLabel
    Left = 248
    Top = 184
    Width = 103
    Height = 20
    Caption = 'Array access:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lArrAccessAmount: TLabel
    Left = 368
    Top = 184
    Width = 9
    Height = 20
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object PanelLeft: TPanel
    Left = 0
    Top = 0
    Width = 233
    Height = 556
    Align = alLeft
    TabOrder = 0
    object lAmount: TLabel
      Left = 16
      Top = 416
      Width = 18
      Height = 20
      Caption = '20'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object sbAmount: TScrollBar
      Left = 96
      Top = 416
      Width = 113
      Height = 20
      Max = 2000000000
      Min = 2
      PageSize = 0
      Position = 100000
      TabOrder = 0
      Visible = False
      OnChange = sbAmountChange
    end
    object bGenerate: TButton
      Left = 48
      Top = 477
      Width = 121
      Height = 60
      Caption = 'Generate numbers'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Visible = False
      OnClick = bGenerateClick
    end
    object rgTableTypes: TRadioGroup
      Left = 35
      Top = 97
      Width = 166
      Height = 320
      Caption = 'Table types: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Items.Strings = (
        'Random'
        'Reversed'
        'Constant'
        'Arrow up'
        'Arrow down'
        'Almost sorted'
        'Few unique'
        'Sorted')
      ParentFont = False
      TabOrder = 2
      OnClick = rgTableTypesClick
    end
  end
  object mTable: TMemo
    Left = 240
    Top = 8
    Width = 369
    Height = 49
    ReadOnly = True
    ScrollBars = ssHorizontal
    TabOrder = 1
    WordWrap = False
  end
  object MainMenu: TMainMenu
    Left = 664
    object mFile: TMenuItem
      Caption = 'File'
      object mStart: TMenuItem
        Caption = 'Start'
        OnClick = mStartClick
      end
      object mGoTo: TMenuItem
        Caption = 'Go To'
        object mDyd: TMenuItem
          Caption = 'Dydatic'
          OnClick = mDydClick
        end
        object mAdv: TMenuItem
          Caption = 'Advanced'
          OnClick = mAdvClick
        end
      end
      object mExit: TMenuItem
        Caption = 'Exit'
        OnClick = mExitClick
      end
    end
    object mHelp: TMenuItem
      Caption = 'Help'
      object mAbout: TMenuItem
        Caption = 'About...'
      end
    end
  end
end
