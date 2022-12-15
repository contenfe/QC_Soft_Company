using System;
using System.Drawing;
using System.Collections.Generic;


using BIMBaseCS.Attributes;
using BIMBaseCS.UI;
using BIMBaseCS.ApplicationService;
using System.Windows.Forms;

namespace StatusBarFramework
{

    [BPExternalCommand(name = "qst")]
    public class CStatus : IBPFunctionCommand
    {
        public override void onExcute(BPCommandContext context)
        {
            IntPtr panelTmp = IntPtr.Zero;
            //Bitmap bmp = new Bitmap(@"D:\Program Files (x86)\PKPM\PKPM\X64\Support\QDPicture\recently_open.png");//null;// Resourcel.triangle;
            //panelTmp = bmp.GetHicon();
            BPUIApplication.singleton().uiManager.uiStatusLayout.statusAddButton("查看文件", "teststatus", true, panelTmp);

            // combox
            List<string> list = new List<string>();
            list.Add("查看修改内容");
            list.Add("打开模板");
            BPUIApplication.singleton().uiManager.uiStatusLayout.statusAddComboBox(list, "teststatus");

            BPUIApplication.singleton().uiManager.uiStatusLayout.statusRecalcLayout();
            
        }

    }

    [BPExternalCommand(name = "teststatus")]
    public class CTestCmd : IBPFunctionCommand
    {
        public override void onExcute(BPCommandContext context)
        {
            string getText = "";
            getText = BPUIApplication.singleton().uiManager.uiStatusLayout.statusGetComboBoxSelectText();

            MessageBox.Show("你选中了: " + getText,"状态栏");
        }
    }

}

[BPExternalCommand(name = "newdock")]
public class CDock : IBPFunctionCommand
{
    public override void onExcute(BPCommandContext context)
    {
        BPNewDockManager manager = new BPNewDockManager();
        BPNewDockManager.setDockPosition(1, "bottom");
        BPNewDockManager.setWindowText(1 ,"啦啦啦啦啦");
        BPNewDockManager.showDockContainer(1 , true);
    }
}