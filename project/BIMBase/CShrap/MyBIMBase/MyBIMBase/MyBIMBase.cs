
using System.Windows.Forms;
using BIMBaseCS.UI;
using BIMBaseCS.Attributes;

namespace MyBIMBase
{
    
    [BPExternalCommand(name = "hello")]
    public class MyBIMBase : IBPFunctionCommand
    {
        public override void onExcute(BPCommandContext context)
        {
            MessageBox.Show("测试样例", "Bimbase命令行");
        }

        
    }
}