using System;
using System.Drawing;
//using System.Drawing.Imaging
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Imaging;
using BIMBaseCS;
using BIMBaseCS.Geometry;
using BIMBaseCS.Tool;
using BIMBaseCS.Attributes;
using BIMBaseCS.UI;
using BIMBaseCS.ApplicationService;
using System.Collections.Generic;

//using BIMBaseCS


namespace ComUI
{
    [Obsolete("过时")]
    [BPExternalCommand(name ="addribbon")]
    public class ApiAddRibbonCommand : IBPFunctionCommand
    {
        public override void onExcute(BPCommandContext context)
        {
            // 添加新的Ribbon菜单项
            BIMBaseCS.UI.tagsize size = new BIMBaseCS.UI.tagsize();
            size.cx = 32;
            size.cy = 32;

            BPUIApplication.singleton().uiManager.uiRibbonPanel.ribbonAddCategory("青橙插件", 16, 16, size, size, 13);

            // 添加新的Ribbon菜单面板
            IntPtr panelTmp = IntPtr.Zero;
            Bitmap bmp = new Bitmap(@"D:\proactive\BimBase\CShrap\MyBIMBase\ComUI\715841.png");//null;// Resourcel.triangle;
            panelTmp = bmp.GetHicon();
            BPUIApplication.singleton().uiManager.uiRibbonPanel.ribbonAddPanel("青橙插件", "测试面板", panelTmp, 1, -1);
            //// 在新的面板上添加菜单按钮
            BPUIApplication.singleton().uiManager.uiRibbonPanel.ribbonAddButton("青橙插件", "测试面板", "打开文件", "hello", panelTmp);


            // 动态关闭窗口
            //BPUIApplication.singleton().uiManager.uiRibbonPanel.dynamicRibbonClose();

            // 获取激活的窗口
            string actwin = BPUIApplication.singleton().uiManager.uiRibbonPanel.ribbonGetActiveCategory();
            if (null != actwin)
                MessageBox.Show(actwin, "当前激活的窗口");

            // 获取所有分类
            try
            {
                //List<string> listCategory = BPUIApplication.singleton().uiManager.uiRibbonPanel.ribbonGetAllCategoryName();
                //BPUIApplication.singleton().uiManager.uiRibbonPanel.ribbonGetAllCategoryName();
                // 暂时不写，写一个工具，将文件保存起来
                //if(listCategory is null)
                //{
                //   ;
                //}


            }
            catch(Exception e)
            {
                MessageBox.Show("获取所有分类失败", "List<string> is null");
            }


            // 隐藏某个分类
            BPUIApplication.singleton().uiManager.uiRibbonPanel.ribbonShowOrHideCategory("帮助", false);



            //base.onExcute(context);

        }
    }
}
