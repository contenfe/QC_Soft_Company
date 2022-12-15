using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using BIMBaseCS.ApplicationService;
using BIMBaseCS.Attributes;
using BIMBaseCS.UI;

namespace TreeItem
{

    [BPExternalCommand(name = "qtr")]
    public class Class1 : IBPFunctionCommand
    {
        public override void onExcute(BPCommandContext context)
        {
            // 清空原本列表
            //BPUIApplication.singleton().treeManager.initialize();

            int sizeoftree = BPUIApplication.singleton().treeManager.size();
            if(sizeoftree > 0)
            {
                MessageBox.Show($"有{sizeoftree}个tree");
            }

            handleTreeItem handle = new handleTreeItem();
            handleTreeItem handles = BPUIApplication.singleton().treeManager.findByName("工程项目/工程场景");

            handleTreeItem temp;
            if(null == handles)
            {
                MessageBox.Show("handles is null");
                temp = handle;
            }
            else
            {
                temp = handles;
            }
            handleTreeItem parentItem = BPUIApplication.singleton().treeManager.append("root -1", "root", temp);
            handleTreeItem childItem1 = BPUIApplication.singleton().treeManager.append("tree -1", "tree_item1", parentItem);
            handleTreeItem childItem2 = BPUIApplication.singleton().treeManager.append("tree -2", "tree_item2", parentItem);
            handleTreeItem childItem3 = BPUIApplication.singleton().treeManager.append("tree -3", "tree_item3", childItem2);
            handleTreeItem childItem4 = BPUIApplication.singleton().treeManager.append("tree -4", "tree_item4", childItem2);
            
            
            
            /***
             * 
             * 判空处理
             * 
             */
            //handleTreeItem treeItem = BPUIApplication.singleton().treeManager.getParentNode(parentItem);
            if (null != parentItem)
            {
               // MessageBox.Show($"{BPUIApplication.singleton().treeManager.getTreeRootItem().ToString()}");
            }
            else
            {
                MessageBox.Show($"树管理 为空");

            }

            //BPUIApplication.singleton().treeManager.

        }
    }
}
