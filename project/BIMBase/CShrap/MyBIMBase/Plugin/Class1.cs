using BIMBaseCS.ApplicationService;
using BIMBaseCS.Attributes;
using BIMBaseCS.Core;
using BIMBaseCS.Data;
using BIMBaseCS.Geometry;
using BIMBaseCS.UI;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace Plugin
{

    #region 命令控制Demo 空
    [BPExternalCommand(name = "config")]
    public class Class1 : IBPFunctionCommand
    {
        public override void onExcute(BPCommandContext context)
        {

        }
    }
    #endregion

    #region 外部应用类
    /// <summary>
    /// 外部应用类
    /// 
    /// 可以通过实现 IExternalApplication 来添加自己的应用。BIMBase 同样通过.plugin 文件来识别和加载实现 IExternalApplication 的外部插件。
    /// IExternalApplication 有两个抽象函数 OnStartup 和 OnShutdown。
    /// 用户可以通过在实现了 IExternalApplication 的外部应用中重载 OnStartup 和 OnShutdown，在 BIMBase 启动和关闭的时候定制所需的功能。
    /// 
    /// </summary>
    public class CExterCmd : IExternalApplication
    {
        readonly string categroyName = "插件";
        readonly string[] panelName = new string[] { "ECPanel", "CSPanel", "TCPanel" };
        uint smallID = 29371;
        uint largeID = 72371;
        public override void onShutdown(BPUIApplication uiApp)
        {
            MessageBox.Show("结束外部应用类");
            
        }

        public override void onStartup(BPUIApplication uiApp)
        {

            
            //MessageBox.Show("结束应用程序");
            tagsize tagsize = new tagsize();
            tagsize.cx = 36;
            tagsize.cy = 36;
            uiApp.uiManager.uiRibbonPanel.ribbonAddCategory(categroyName, smallID, largeID, tagsize, tagsize, -1);

            IntPtr intPtr = IntPtr.Zero;

            Bitmap bmp = new Bitmap(@"D:\Program Files (x86)\PKPM\PKPM\X64\Support\QDPicture\NewLock.png");//null;// Resourcel.triangle;
            intPtr = bmp.GetHicon();

            // 创建面板
            uiApp.uiManager.uiRibbonPanel.ribbonAddPanel(categroyName, panelName[0], IntPtr.Zero, 1, 0);
            uiApp.uiManager.uiRibbonPanel.ribbonAddPanel(categroyName, panelName[1], IntPtr.Zero, 1, 1);
            uiApp.uiManager.uiRibbonPanel.ribbonAddPanel(categroyName, panelName[2], IntPtr.Zero, 1, 2);

            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[0], "点击-画线", "line_point", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[0], "命令-画线", "line_input", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[0], "命令-立方体", "cubes_origin", intPtr);

            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "点击-立方体", "cubes_onclik", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "创建项目树", "qtr", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "状态栏按钮", "qst", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "点击-球", "sphere_onclik", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "点击-弯管", "pipe_onclik", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "点击-扫掠体类", "ruledsweep_onclik", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "点击-台柱类", "cone_onclick", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "点击-面", "curve_onclick", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "点击-面三角形", "curve2_onclick", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "点击-面线段", "curve3_onclick", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "点击-任意多边形", "random", intPtr);
            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "dock", "newdock", intPtr);

            uiApp.uiManager.uiRibbonPanel.ribbonAddButton(categroyName, panelName[1], "拉伸体实验", "cmdextrusion", intPtr);
            //ShowMousePoint();
        }


        [Obsolete("废弃")]
        private void ShowMousePoint()
        {
            string currentName = BPApplication.singleton().activeDocument.userEnvironment.getCurrentDomainKeyName();
            BPCommandContext context = new BPCommandContext();
            GePoint3d gepoint = context.mousePoint;
            if (null == gepoint)
            {
                Button button = new Button();
                button.Text="IS OK!";
                MessageBox.Show($"{currentName}");
                return;
            }
            MessageBox.Show($"x:{gepoint.x} y:{gepoint.y}");
        }
    }

    #endregion

    #region 获取鼠标
    [BPExternalCommand(name = "mouse")]
    public class CCommendText : IBPFunctionCommand
    {
        public override void onExcute(BPCommandContext context)
        {

            //GePlane3d gp = new GePlane3d();

            float s = 100;
            float s2 = 0;
           
            
            //BPCommandContext bpct = new BPCommandContext();
            if(context == null)
            {
                MessageBox.Show("创建BPCommandContext失败");
                return;
            }

            GePoint3d mousepoint = context.mousePoint;
            if(mousepoint != null)
            {

                MessageBox.Show($"x:{mousepoint.x} y:{mousepoint.y}");
            }
            else
            {
                MessageBox.Show("获取鼠标失败");
            }
        }
    }
    #endregion

    #region 画线 -鼠标点
    // API:点选命令中的左右键，动态，键盘事件以及工具退出和启动的函数
    [BPExternalCommand(name = "line_point")]
    public class CPointFun : IBPPointCommand
    {

        GePoint3d point3_start;
        GePoint3d point3_end;
        bool m_bFlag;

        public CPointFun()
        {
            m_bFlag = false;
        }

        public override bool onLeftClick(BPCommandContext context)
        {
            if(false == m_bFlag)
            {
                m_bFlag = true;
                point3_start = context.mousePoint;
            }
            else if(true == m_bFlag)
            {
                m_bFlag = false;
                point3_end = context.mousePoint;
                BPGraphics graphic = createCraphic();
                graphic.save();
            }


            return true;
        }


        public override void onDynamicDraw(BPCommandContext context)
        {
            if (false == m_bFlag) return;

            point3_end = context.mousePoint;
            BPViewport vp = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            BPGraphics graphics = createCraphic();
            vp.dynamicDraw(graphics);
        }

        public BPGraphics createCraphic()
        {
            BPViewport vp = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            BPModel model = vp.targetModel;
            BPGraphics graphic = new BPGraphics(model);
            GeSegment3d line = new GeSegment3d(point3_start, point3_end);
            // static IGeCurveBase ^  createSegment (GeSegment3d^ segment) 
            graphic.addCurve(IGeCurveBase.createSegment(line));
            return graphic;
        }
    }
    #endregion

    #region TODOselected
    [BPExternalCommand(name = "view")]
    public class CView : IBPSelectCommand
    {
        public override bool canBeSelect(BPGraphics graphic)
        {
            return base.canBeSelect(graphic);
        }

        public override bool onClickSelected(BPGraphics graphic, BPCommandContext context)
        {
            return base.onClickSelected(graphic, context);
        }

        public override void onExitTool()
        {
            base.onExitTool();
        }

        public override bool onKeyDown(BPVirtualKey key, bool shiftIsDown, bool ctrlIsDown)
        {
            return base.onKeyDown(key, shiftIsDown, ctrlIsDown);
        }

        public override bool onKeyUp(BPVirtualKey key, bool shiftIsDown, bool ctrlIsDown)
        {
            return base.onKeyUp(key, shiftIsDown, ctrlIsDown);
        }

        public override bool onLeftClick(BPCommandContext context)
        {
            return base.onLeftClick(context);
        }

        public override bool onRightClick(BPCommandContext context)
        {
            return base.onRightClick(context);
        }
    }
    #endregion

    #region TODO测试获取鼠标位置


    [BPExternalCommand(name ="bctmouse")]
    public class CMousePoint : IBPPointCommand
    {
        GePoint3d m_point3Start;
        GePoint3d m_point3End;
        bool m_bFlag = false;
        public override bool onKeyDown(BPVirtualKey key, bool shiftIsDown, bool ctrlIsDown)
        {
            if(shiftIsDown && ctrlIsDown)
            {
                if(BPVirtualKey.Up == key)
                {
                    BPGraphics graphics = CreateGraphics();
                    graphics.save();
                    return true;
                }

                return false;
            }

            return false;
            
        }

        public override void onDynamicDraw(BPCommandContext context)
        {
            if (m_bFlag == false)
                return;
            m_point3End = context.mousePoint;
            BPViewport viewport = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            BPGraphics graphics = CreateGraphics();
            viewport.dynamicDraw(graphics);
            
        }

        private BPGraphics CreateGraphics()
        {
            BPViewport viewport = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            //BPDocument document=BPApplication.singleton().activeDocument;
            BPModel model = viewport.targetModel;//new BPModel(document);
            BPGraphics graphics = new BPGraphics(model);
            GeSegment3d line = new GeSegment3d(m_point3Start, m_point3End);
            graphics.addCurve(IGeCurveBase.createSegment(line));

            return graphics;
        }

        public override bool onLeftClick(BPCommandContext context)
        {
            // 异常处理
            if (null == context.mousePoint)
                return false;

            if(false == m_bFlag)
            {
                m_bFlag = true;                                                           // 标记，切换结束点和开始点
                m_point3Start = context.mousePoint;
            }
            else if(true == m_bFlag)
            {
                m_bFlag = false;
                m_point3End = context.mousePoint;

                // 保存绘画结果
                BPGraphics graphics = CreateGraphics();
                graphics.save();
            }

            return true;
        }
    }
    #endregion

    #region 画线 -带数据输入
    [BPExternalCommand(name = "line_input")]
    public class CCamd : IBPFunctionCommand
    {

        /// <summary>
        /// 划线
        /// </summary>
        /// <param name="context"></param>
        public override void onExcute(BPCommandContext context)
        {
            BPDocument doc = BPApplication.singleton().activeDocument;
            BPModel model = doc.modelManager.activeModel;
            BPGraphics graphic = new BPGraphics();

            GePoint3d ptBase = GePoint3d.createByZero();
            GePoint3d pt = GePoint3d.createByZero();
            BPAdsFun.GetPoint(null, "请选择起点", ref ptBase);
            BPAdsFun.GetPoint(ptBase, "请选择终点", ref pt);

            graphic.addCurve(IGeCurveBase.createSegment(new GeSegment3d(ptBase, pt)));
            graphic.save();

        }

    }

    #endregion

    #region 画立方体 - 在原点画 

    [BPExternalCommand(name = "cubes_origin")]
    public class CCubeT : IBPFunctionCommand
    {
        public override void onExcute(BPCommandContext context)
        {
            BPDocument document = BPApplication.singleton().activeDocument;

            // 获取当前激活的视口
            BPViewport viewport = document.viewManager.getActivedViewport();

            // 创建Graphics
            BPGraphics graphics = new BPGraphics();

            // 创建Point3d 对象
            GePoint3d _pointStart = context.mousePoint;
            if(null == _pointStart)
            {
                MessageBox.Show("_pointStart is null");
                _pointStart = GePoint3d.createByZero();
            }

            _pointStart.x = 200;
            _pointStart.y = 200;
            _pointStart.z = 200;
            GePoint3d _pointEnd = new GePoint3d(_pointStart);
            _pointEnd.z += 100;

            // Vec 向量
            GeVec3d vec_bottom_x = new GeVec3d(1, 0, 0);
            GeVec3d vec_bottom_y = new GeVec3d(0, 1, 0);

            // 创建BoxInfo 对象
            GeBoxInfo boxinfo = new GeBoxInfo(_pointStart, _pointEnd, vec_bottom_x, vec_bottom_y, 50, 50, 50, 50, true);

            // 绘制
            graphics.addSolid(IGeSolidBase.createBox(boxinfo));
            graphics.save();



        }
    }
    #endregion

    #region TODO在功能命令类中获取上下文

    [BPExternalCommand(name = "getcontext")]
    public class CContextC : IBPFunctionCommand
    {
        public override void onExcute(BPCommandContext context)
        {
            
            if(null == context)
            {
                MessageBox.Show("context is null");
                BPApplication.singleton().activeDocument.userInputManager.getCurCommand();
                BPUIApplication.singleton().uiManager.uiStatusLayout.statusAddButton("test context", "tools", true, IntPtr.Zero);
            }
            else
            {
                MessageBox.Show(" context is not null");
            }
        }
    }

    #endregion

    #region 立方体 -鼠标点 
    // 拉伸体

    [BPExternalCommand(name ="cubes_onclik")]
    public class CStrain : IBPPointCommand
    {
        GePoint3d m_pointStart;
        public override void onDynamicDraw(BPCommandContext context)
        {
            base.onDynamicDraw(context);
        }

        public override bool onLeftClick(BPCommandContext context)
        {
            //BPText text = 
            m_pointStart = context.mousePoint;
            if(m_pointStart == null)
            {
                MessageBox.Show("拉伸体为空");
                return false ;
            }


            BPGraphics graphics = createGraphics();
            graphics.save();
            return true;
        }

        private BPGraphics createGraphics()
        {

            BPViewport viewport = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            BPModel model = viewport.targetModel;

            BPGraphicElement element = new BPGraphicElement();
            BPGraphics graphics =  element.createGraphics(model);



            // 存储坐标
            List<GePoint3d> points = new List<GePoint3d>();
            points.Add(new GePoint3d(m_pointStart));
            points.Add(new GePoint3d(m_pointStart.x+2000, m_pointStart.y, m_pointStart.z));
            points.Add(new GePoint3d(m_pointStart.x + 2000, m_pointStart.y+2000, m_pointStart.z));
            points.Add(new GePoint3d(m_pointStart.x, m_pointStart.y+2000, m_pointStart.z));
           // points.Add(new GePoint3d(0, 0, 0));


            GeCurveArray curve = GeCurveArray.createLinestringArray(points, GeCurveArray.BoundaryType.None, true);

            // 三维向量
            GeVec3d vec = new GeVec3d(0, 0, 2000);

            GeExtrusionInfo extrusionInfo = new GeExtrusionInfo(curve, vec, true);

            IGeSolidBase solidbase = IGeSolidBase.createExtrusion(extrusionInfo);

            graphics.addSolid(solidbase);

            return graphics;
        }
    }



    #endregion

    #region 球 -鼠标点 
    // 拉伸体

    [BPExternalCommand(name = "sphere_onclik")]
    public class CSphere : IBPPointCommand
    {
        GePoint3d m_pointCenter;
        float m_r = 20.0f;
        public override void onDynamicDraw(BPCommandContext context)
        {
            base.onDynamicDraw(context);
        }

        public CSphere()
        {
            BPMessageCenter.sendMessage("点击放置球体位置");
        }

        public override bool onLeftClick(BPCommandContext context)
        {
            //BPText text = 
            m_pointCenter = context.mousePoint;
            if (m_pointCenter == null)
            {
                MessageBox.Show("获取鼠标位置失败");
                return false;
            }


            BPGraphics graphics = createGraphics();
            graphics.save();
            return true;
        }

        private BPGraphics createGraphics()
        {

            BPViewport viewport = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            BPModel model = viewport.targetModel;

            BPGraphicElement element = new BPGraphicElement();
            BPGraphics graphics = element.createGraphics(model);


            GeSphereInfo sphereinfo = new GeSphereInfo(m_pointCenter, m_r);

            IGeSolidBase solidbase = IGeSolidBase.createSphere(sphereinfo);

            graphics.addSolid(solidbase);

            return graphics;
        }
    }



    #endregion

    #region 弯管 -鼠标点 
    // 拉伸体

    [BPExternalCommand(name = "pipe_onclik")]
    public class CTorusPipe : IBPPointCommand
    {
        GePoint3d m_pointBigCenter;
        GeVec3d m_vecX = new GeVec3d(5, 0, 0);
        GeVec3d m_vecY = new GeVec3d(0, 5, 0);

        float m_majorR = 10.0f;                                                           // 大圆半径
        float m_minorR = 5f;                                                              // 弯管半径
        float sweep_angle = 90f;                                                          // 大圆扫掠角度
        public override void onDynamicDraw(BPCommandContext context)
        {
            base.onDynamicDraw(context);
        }

        public override bool onLeftClick(BPCommandContext context)
        {
            //BPText text = 
            m_pointBigCenter = context.mousePoint;
            if (m_pointBigCenter == null)
            {
                MessageBox.Show("获取鼠标位置失败");
                return false;
            }


            BPGraphics graphics = createGraphics();
            graphics.save();
            return true;
        }

        private BPGraphics createGraphics()
        {

            BPViewport viewport = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            BPModel model = viewport.targetModel;

            BPGraphicElement element = new BPGraphicElement();
            BPGraphics graphics = element.createGraphics(model);


            GeTorusPipeInfo info = new GeTorusPipeInfo(m_pointBigCenter, m_vecX, m_vecY, m_majorR, m_minorR, sweep_angle,false);

            IGeSolidBase solidbase = IGeSolidBase.createTorusPipe(info);

            graphics.addSolid(solidbase);

            return graphics;
        }
    }



    #endregion

    #region TODO扫掠体类 -鼠标点 
    // 拉伸体

    [BPExternalCommand(name = "ruledsweep_onclik")]
    public class CRuledSweep : IBPPointCommand
    {
        GePoint3d m_pointCenter;
        
        public override void onDynamicDraw(BPCommandContext context)
        {
            base.onDynamicDraw(context);
        }

        public override bool onLeftClick(BPCommandContext context)
        {
            //BPText text = 
            m_pointCenter = context.mousePoint;
            if (m_pointCenter == null)
            {
                MessageBox.Show("获取鼠标位置失败");
                return false;
            }


            BPGraphics graphics = createGraphics();
            graphics.save();
            return true;
        }

        private BPGraphics createGraphics()
        {

            BPViewport viewport = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            BPModel model = viewport.targetModel;

            BPGraphicElement element = new BPGraphicElement();
            BPGraphics graphics = element.createGraphics(model);

            GeCurveArray curveArray1 = new GeCurveArray(GeCurveArray.BoundaryType.Outer);
            GeCurveArray curveArray2 = new GeCurveArray(GeCurveArray.BoundaryType.Outer);

            GeRuledSweepInfo info = new GeRuledSweepInfo(curveArray1, curveArray2,true);



            IGeSolidBase solidbase = IGeSolidBase.createRuledSweep(info);

            graphics.addSolid(solidbase);

            return graphics;
        }
    }



    #endregion

    #region 台柱 -鼠标点

    [BPExternalCommand(name = "cone_onclick")]
    public class CMessage : IBPPointCommand
    {
        GePoint3d m_bottomCenter;
        GePoint3d m_topCenter;
        double m_bottomR = double.MaxValue;
        double m_topR = double.MaxValue;



        public override bool onLeftClick(BPCommandContext context)
        {
            if(null == context.mousePoint)
            {
                BPMessageCenter.sendMessage("获取鼠标位置失败");
                return false;
            }
            
            //Convert.ToDouble()
            //m_bottomR = Convert.ToDouble(BPAdsFun.GetInput());
            //m_topR = Convert.ToDouble(BPAdsFun.GetInput());

            //if(Double.MaxValue == m_bottomR)
            //{
            //    BPMessageCenter.sendMessage("未获取值bottomValue");
            //}
                m_bottomR = 20;

            //if (Double.MaxValue == m_bottomR)
            //{
            //    BPMessageCenter.sendMessage("未获取值topValue");
            //}
                m_topR = 10;


            m_bottomCenter = context.mousePoint;
            m_topCenter = new GePoint3d(m_bottomCenter);
            m_topCenter.z += 80;


            GeConeInfo info = new GeConeInfo(m_bottomCenter, m_topCenter, m_bottomR, m_topR, true);
            BPGraphics graphics = new BPGraphics();
            graphics.addSolid(IGeSolidBase.createCone(info));
            graphics.save();


            return true;
        }
    }


    #endregion

    #region 多边形

    [BPExternalCommand(name ="curve_onclick")]
    public class CCurveArray : IBPPointCommand
    {

        private List<GePoint3d> m_listPoint = new List<GePoint3d>();
        private bool m_bPress = false;

        public override void onDynamicDraw(BPCommandContext context)
        {
            if (!m_bPress) return;
            //m_listPoint.Add(context.mousePoint);
            //m_listPoint.Add(context.mousePoint);
            BPGraphics graphics = createGraphics();
            graphics.save();
        }


        /***
         * 
         * 键盘监听事件
         */
        public override bool onKeyDown(BPVirtualKey key, bool shiftIsDown, bool ctrlIsDown)
        {

            if (BPVirtualKey.Shift == key)
            {
                m_bPress = true;
                return true;
            }
            return false;
        }

        /***
         * 
         * 键盘监听事件
         */
        public override bool onKeyUp(BPVirtualKey key, bool shiftIsDown, bool ctrlIsDown)
        {
            if(BPVirtualKey.Shift == key)
            {
                m_bPress = false;
                
                
                BPGraphics graphics = createGraphics();
                graphics.save();
                return true;
            }
            return false;
        }



        public override bool onLeftClick(BPCommandContext context)
        {
            if(!m_bPress)
            {
                BPMessageCenter.sendMessage("未按下Shift键");
                return false;
            }
           
            m_listPoint.Add(context.mousePoint);
           


            return true;
        }

        private BPGraphics createGraphics()
        {
            BPViewport viewport = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            BPModel model = viewport.targetModel;
            BPGraphics graphics = new BPGraphics(model);
            GeCurveArray array = new GeCurveArray(GeCurveArray.BoundaryType.Outer);

            graphics.addCurve(IGeCurveBase.createLineString(m_listPoint));
            return graphics;
        }
    }


    #endregion


    #region BUG多边形2

    [BPExternalCommand(name = "curve2_onclick")]
    public class CCurveArray2 : IBPPointCommand
    {

        private List<GePoint3d> m_listPoint = new List<GePoint3d>();
        private bool m_bPress = false;

        public override void onDynamicDraw(BPCommandContext context)
        {
            if (!m_bPress) return;
            //m_listPoint.Add(context.mousePoint);
            //m_listPoint.Add(context.mousePoint);
            BPGraphics graphics = createGraphics();
            graphics.save();
        }


        /***
         * 
         * 键盘监听事件
         */
        public override bool onKeyDown(BPVirtualKey key, bool shiftIsDown, bool ctrlIsDown)
        {

            if (BPVirtualKey.Shift == key)
            {
                m_bPress = true;
                return true;
            }
            return false;
        }

        /***
         * 
         * 键盘监听事件
         */
        public override bool onKeyUp(BPVirtualKey key, bool shiftIsDown, bool ctrlIsDown)
        {
            if (BPVirtualKey.Shift == key)
            {
                m_bPress = false;


                BPGraphics graphics = createGraphics();
                graphics.save();
                return true;
            }
            return false;
        }



        public override bool onLeftClick(BPCommandContext context)
        {
            if (!m_bPress)
            {
                BPMessageCenter.sendMessage("未按下Shift键");
                return false;
            }

            m_listPoint.Add(context.mousePoint);

            return true;
        }

        private BPGraphics createGraphics()
        {
            BPViewport viewport = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            BPModel model = viewport.targetModel;
            BPGraphics graphics = new BPGraphics(model);
            GeCurveArray array = GeCurveArray.createLinestringArray(m_listPoint, GeCurveArray.BoundaryType.Inner,true);



            graphics.addCurve(IGeCurveBase.createChildCurveArray(array));
            return graphics;
        }
    }


    #endregion

    #region BUG多边形3
    /// <summary>
    /// 根据线段创建GeCurve
    /// </summary>
    [BPExternalCommand(name = "curve3_onclick")]
    public class CCurveArray3 : IBPPointCommand
    {

        private List<GeSegment3d> m_listSegment = new List<GeSegment3d>();
        private bool m_bPress = false;
        
        private bool m_bFlag = false;
        private GePoint3d m_pointStart;
        private GePoint3d m_pointEnd;

        public override void onDynamicDraw(BPCommandContext context)
        {
            if (!m_bPress) return;
            //m_listPoint.Add(context.mousePoint);
            //m_listPoint.Add(context.mousePoint);
            BPGraphics graphics = createGraphics();
            graphics.save();
        }


        /***
         * 
         * 键盘监听事件
         */
        public override bool onKeyDown(BPVirtualKey key, bool shiftIsDown, bool ctrlIsDown)
        {

            if (BPVirtualKey.Shift == key)
            {
                m_bPress = true;
                return true;
            }
            return false;
        }

        /***
         * 
         * 键盘监听事件
         */
        public override bool onKeyUp(BPVirtualKey key, bool shiftIsDown, bool ctrlIsDown)
        {
            if (BPVirtualKey.Shift == key)
            {
                m_bPress = false;

                m_pointStart = null;
                m_pointEnd = null;
                m_bFlag = false;
                m_listSegment.Clear();

                BPGraphics graphics = createGraphics();
                graphics.save();
                return true;
            }
            return false;
        }



        public override bool onLeftClick(BPCommandContext context)
        {
            if (!m_bPress)
            {
                BPMessageCenter.sendMessage("未按下Shift键");
                return false;
            }
            if(false == m_bFlag)
            {
                m_bFlag = true;
                if(null != m_pointEnd)
                {
                    m_pointStart = m_pointEnd;
                }
                else
                {
                    m_pointStart = context.mousePoint;
                }
            }
            else if(true == m_bFlag)
            {
                m_bFlag = false;
                m_pointEnd = context.mousePoint;
                GeSegment3d segment = new GeSegment3d(m_pointStart, m_pointEnd);
                m_listSegment.Add(segment);
            }

            return true;
        }

        private BPGraphics createGraphics()
        {
            BPViewport viewport = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            BPModel model = viewport.targetModel;
            BPGraphics graphics = new BPGraphics(model);
            GeCurveArray array = GeCurveArray.create(m_listSegment);
            


            graphics.addCurve(IGeCurveBase.createChildCurveArray(array));
            return graphics;
        }
    }


    #endregion


    #region 任意多边形

    [BPExternalCommand(name = "random")]
    public class CRandom : IBPPointCommand
    {
        GePoint3d m_pointStart = null;
        GePoint3d m_pointEnd = null;
        List<GeSegment3d> m_listSegment = new List<GeSegment3d>();
        List<GePoint3d> m_listPoint = new List<GePoint3d>();
        bool m_bStart = true;


        public override bool onKeyDown(BPVirtualKey key, bool shiftIsDown, bool ctrlIsDown)
        {
            if(BPVirtualKey.Tab == key)
            {
                GePoint3d point = GePoint3d.createByZero();

                if (null == m_pointStart && m_bStart)
                {

                    BPAdsFun.GetPoint(null, "请输入一个起始点", ref point);
                    m_pointStart = point;

                    m_listPoint.Add(point);
                    m_bStart = false;
                }
                else
                {
                    BPAdsFun.GetPoint(m_listPoint[m_listPoint.Count - 1], "请输入点", ref point);

                    GeSegment3d seg = new GeSegment3d(m_listPoint[m_listPoint.Count - 1], point);
                    m_pointEnd = point;
                    m_listSegment.Add(seg);
                    m_listPoint.Add(m_pointEnd);
                    BPGraphics graphics = createGraphics();
                    //graphics.addCurve(IGeCurveBase.createSegment(seg));
                    graphics.save();


                }
                
            }

            //if(BPVirtualKey.Shift == key)
            //{
            //    //GePlane3d plane = new GePlane3d(m_pointStart,new GeVec3d(0,0,1));
            //    //plane.projectPointToPlane
            //}
            
            return true;
        }

        public override void onDynamicDraw(BPCommandContext context)
        {
            if (true == m_bStart) return;

            GePoint3d point = context.mousePoint;

            GeSegment3d seg_e = new GeSegment3d(m_pointStart, point);
            GeSegment3d seg_s = new GeSegment3d(m_listPoint[m_listPoint.Count - 1], point);
            BPViewport viewport = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            BPGraphics graphics = createGraphics();
            graphics.addCurve(IGeCurveBase.createSegment(seg_e));
            graphics.addCurve(IGeCurveBase.createSegment(seg_s));
            viewport.dynamicDraw(graphics);

        }

        public override bool onLeftClick(BPCommandContext context)
        {
            //BPText text = null;
            if(null == context.mousePoint)
            {
                BPMessageCenter.sendMessage("错误,未检测到鼠标位置");
                return false;
            }

            BPGeSymbology color = new BPGeSymbology();
            color.color = Color.LightCoral;
            color.style = 1;
            color.weight = 1;

            BPApplication.singleton().activeDocument.viewManager.getActivedViewport().setSymbologyRgb(Color.Blue, Color.Green, 12, 12);


            BPMessageCenter.sendMessage("press右键结束");

            if(true == m_bStart)
            {
                m_pointStart = context.mousePoint;
                m_listPoint.Add(m_pointStart);
                m_bStart = false;
            }
            else if(false == m_bStart)
            {
                m_pointEnd = context.mousePoint;

                GeSegment3d ge = new GeSegment3d(m_listPoint[m_listPoint.Count-1], m_pointEnd);
                m_listPoint.Add(new GePoint3d(m_pointEnd));
            }

            BPGraphics graphics = createGraphics();
            graphics.save();
            
            

            return true;
        }

        private BPGraphics createGraphics()
        {
            BPViewport viewport = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();
            BPModel model = viewport.targetModel;
            BPGraphics graphics = new BPGraphics(model);

            GeCurveArray array = GeCurveArray.create(m_listSegment);
            graphics.addCurve(IGeCurveBase.createLineString(m_listPoint));

#if false
            // API : 显示内容，文本左下角坐标，单行旋转变换矩阵，文本属性
            try
            {
                GeTransform transform = GeTransform.create(m_listPoint[m_listPoint.Count - 1]); // 可能要延迟加入listpoint m_pointEnd
                GeRotMatrix matrix = GeRotMatrix.createByTransform(transform);

                string str = $"数据{m_listPoint.Count}";
                GePoint3d origin = m_listPoint[m_listPoint.Count - 1];
                BPTextProperties properties = BPTextProperties.create("宋体", "宋体",
                       GePoint2d.create(16, 16),
                       BPApplication.singleton().activeDocument.viewManager.getActivedViewport().targetModel);
                BPText text = null;
                if (null != origin && null != properties && null != matrix)
                {
                    text = BPText.create(str, origin, matrix, properties);
                }

                if (null != text)
                {
                    graphics.addText(text);
                }
                throw new ArgumentNullException(" text is null ");
            }catch(Exception e)
            {
                BPMessageCenter.sendMessage(e.Message);
            }
#endif        

            return graphics;
        }

        public override bool onRightClick(BPCommandContext context)
        {
            if (m_pointStart == null || m_pointEnd == null)
            {
                
                BPMessageCenter.sendMessage("错误未选择点");
                return false;
            }

            // 连接起点和终点
            BPViewport viewport = BPApplication.singleton().activeDocument.viewManager.getActivedViewport();

            GeSegment3d ge = new GeSegment3d(m_pointStart, m_pointEnd);
            BPGraphics graphics = createGraphics();
            graphics.addCurve(IGeCurveBase.createSegment(ge));
            graphics.save();

            // 创建面
#if false
            GeCurveArray array = GeCurveArray.create(m_listSegment);
            string str_err = "错误";
            BPHatch hatch = new BPHatch("测试", array, ref str_err);
            hatch.hatchLoop = array;
            hatch.appendLoop(BPHatch.HatchLoopType.kDefault,)
#endif
            //

            // 
            PolyfaceHandle handle = PolyfaceHandle.createVariableSizeIndexed();
            // handle.addPolygon(m_listPoint);
            graphics.addPolyface(handle);
            //graphics.addText(new BPText("asdf"));
            //BPApplication.singleton().activeDocument.viewManager.getActivedViewport();

            // viewport.dynamicDraw(graphics);

            // 清理
            Clearn();

            // 注销插件
            

            return true;
        }

        private void Clearn()
        {
            m_pointEnd = null;
            m_pointStart = null;

            m_listSegment.Clear();
            m_listPoint.Clear();
            
            m_bStart = true;
        }
    }
#endregion

#region 创建拉伸体
    [BPExternalCommand(name = "cmdstrain")]
    public class CCmdStrain : IBPFunctionCommand
    {
        
        public override void onExcute(BPCommandContext context)
        {
            CCreateStrain strain = CCreateStrain.getSigleton;
            strain.show();
        }
    }
    public class CCreateStrain : BPGraphicElement
    {
        private CCreateStrain()
        {

        }
        private static CCreateStrain m_cCmd = new CCreateStrain();

        int m_iLength = 2000;
        int m_iWidth = 1500;
        int m_iHeight = 3000;
        public static CCreateStrain getSigleton
        {
            get{
                if(m_cCmd == null)
                {
                    m_cCmd = new CCreateStrain();
                }
                return m_cCmd;
            }
        }

        public void show()
        {
            List<GePoint3d> list =  _createGripPoints();


            //_dragGripPoints(1,);
            BPGraphics graphics = _createGraphics(BPApplication.singleton().activeDocument.viewManager.getActivedViewport().targetModel);
            graphics.save();
        }
        
        protected override BPGraphics _createGraphics(BPModel model)
        {
            // 图形类
            BPGraphics graphics = new BPGraphics(model);

            // 存储坐标
            List<GePoint3d> points = new List<GePoint3d>();
            points.Add(new GePoint3d(0, 0, 0));
            points.Add(new GePoint3d(m_iLength, 0, 0));
            points.Add(new GePoint3d(m_iLength, m_iWidth, 0));
            points.Add(new GePoint3d(0, m_iWidth, 0));
            points.Add(new GePoint3d(0, 0, 0));

            // 曲线组 对象类
            /***
             * 根据点list和类型创建GeCurveArray 
             * GeCurveArray.createLinestringArray(points, GeCurveArray.BoundaryType.Outer, false);
             * 
             * None：无类型；Open：开放曲线；Outer：闭合外轮廓曲线；Inner：闭合内轮廓曲线；
             * ParityRegion：区域求交；UnionRegion：区域求并 
             * 
             */
            GeCurveArray curve = GeCurveArray.createLinestringArray(points, GeCurveArray.BoundaryType.Outer, false);

            graphics.addCurve(IGeCurveBase.createChildCurveArray(curve));
            graphics.save();
            // 三维向量
            GeVec3d vec = new GeVec3d(0, 0, m_iHeight);

            // 拉伸体类
            /***
             * curve 截面
             * vec 拉伸向量
             * capped 拉伸体两端是否封闭
             */
            GeExtrusionInfo extrusionInfo = new GeExtrusionInfo(curve, vec, true);

            // 几何实体类
            IGeSolidBase solid = IGeSolidBase.createExtrusion(extrusionInfo);
            // 添加实体
            graphics.addSolid(solid);



            return graphics;
        }

        /// <summary>
        /// 创建自己的夹点
        /// </summary>
        /// <returns></returns>
        protected override List<GePoint3d> _createGripPoints()
        {
            // 变换矩阵类
            GeTransform transform = GeTransform.create(new GePoint3d(m_iLength, m_iWidth, m_iHeight));

            List<GePoint3d> listPt = new List<GePoint3d>();
            listPt.Add(new GePoint3d(m_iLength / 2, m_iWidth / 2, 0));
            listPt.Add(new GePoint3d(m_iLength / 2, m_iWidth / 2, m_iHeight));
            listPt.Add(new GePoint3d(m_iLength / 2, 0, m_iHeight / 2));
            listPt.Add(new GePoint3d(m_iLength / 2, m_iWidth, m_iHeight / 2));
            listPt.Add(new GePoint3d(0, m_iWidth / 2, m_iHeight / 2));
            listPt.Add(new GePoint3d(m_iLength, m_iWidth / 2, m_iHeight / 2));

            return listPt;
        }

        protected override void _dragGripPoints(uint index, GePoint3d grippt, GePoint3d msPos)
        {
            GeTransform transform = GeTransform.create(new GePoint3d(m_iLength, m_iWidth, m_iHeight));
            // 该类封装图形构件的位置信息。
            BPPlacement placement = new BPPlacement();
            // 创建变换矩阵的matrix部分为单位矩阵
            GeTransform trans = GeTransform.createIdentityMatrix();

            switch (index)
            {
                case 0:
                    m_iHeight = m_iHeight + (int)(grippt.z - msPos.z);
                    // 创建一个变换矩阵为两个矩阵 transform1 和 transform2 相乘结果
                    trans = GeTransform.create(new GePoint3d(0, 0, msPos.z - grippt.z));
                    placement.fromTransform(GeTransform.createByProduct(trans, transform));
                    //setPlacement(placement);
                    break;
                case 1:
                    m_iHeight = m_iHeight + (int)(msPos.z - grippt.z);
                    break;
                case 2:
                    m_iWidth = m_iWidth + (int)(msPos.y - grippt.y);
                    break;
            }

        }
    }

    #region 起动类 no use
    [BPExternalCommand(name = "cmdextrusion")]
    public class CExtrusion : IBPPointCommand
    {
        public override void onDynamicDraw(BPCommandContext context)
        {
            
        }

        public override bool onLeftClick(BPCommandContext context)
        {
            if(null == context.mousePoint)
            {
                BPMessageCenter.sendMessage("位置不能为空");
                return false;
            }


            List<GePoint3d> list = new List<GePoint3d>();
            list.Add(new GePoint3d(0, 0, 0));
            list.Add(new GePoint3d(200, 0, 0));
            list.Add(new GePoint3d(200, 200, 0));
            list.Add(new GePoint3d(0, 200, 0));
            
            
            GeCurveArray curve = GeCurveArray.createLinestringArray(list, GeCurveArray.BoundaryType.Outer, true);
            BPGraphics graphics = new BPGraphics(BPApplication.singleton().activeDocument.viewManager.getActivedViewport().targetModel);

            graphics.addCurve(IGeCurveBase.createChildCurveArray(curve));
            graphics.save();

            return true;
        }
    }
    #endregion

    #endregion


    #region 拉伸体2

    [BPExternalCommand(name ="s2")]
    public class CCStrain2 : IBPPointCommand
    {
        List<GePoint3d> m_listPoint = new List<GePoint3d>();


        // box info         X  Y 
        GePoint3d m_centerbtm;                                             // 底部中心点
        GePoint3d m_centertop;                                             // 顶部中心点
        GePoint3d m_centerbox;                                             // box 中心，鼠标点的位置
        readonly double m_height;                                          // 高
        readonly double m_btmlargth;                                       // 长
        readonly double m_btmwidth;                                        // 宽
        readonly double m_toplargth;                                       // 长
        readonly double m_topwidth;                                        // 宽
        GeVec3d m_vecXbtm;                                                 // 向量X方向
        GeVec3d m_vecYbtm;                                                 // 向量Y方向
        GeBoxInfo box;

        public CCStrain2()
        {
            m_height = 20;
            m_btmwidth = 10;
            m_btmlargth = 10;
            m_toplargth = 10;
            m_topwidth = 10;
            m_vecXbtm = new GeVec3d(1, 0, 0);
            m_vecYbtm = new GeVec3d(0, 1, 0);
        }


        public override bool onLeftClick(BPCommandContext context)
        {
            if(null == context.mousePoint)
            {
                BPMessageCenter.sendMessage("鼠标位置获取失败");

                return false;
            }

            m_centerbox = context.mousePoint;
            m_centerbtm = new GePoint3d(m_centerbox.x,m_centerbox.y,m_centerbox.z-m_height/2);
            m_centertop = new GePoint3d(m_centerbox.x, m_centerbox.y, m_centerbox.z + m_height / 2);

            // 底部中心，顶部中心，方向x,方向y,底长,底宽，顶长，顶宽
            box = new GeBoxInfo(m_centerbtm, m_centertop, m_vecXbtm, 
                m_vecYbtm, m_btmlargth, m_btmwidth, m_toplargth, m_topwidth, true);

            // 截面，拉伸向量
            List<GeCurveArray> listcurve = createListCurveAarry();
            GeVec3d up = new GeVec3d(0, 0, 1);
            GeExtrusionInfo extrusioninfo = new GeExtrusionInfo(listcurve[0],up,true);
            BPGraphicElement element = new BPGraphicElement();

            // behavior
            

            
            // act
            //element.dragGripPoints(0, beforecenterpoint, aftercenterpoint);


            // 创建BPGraphics 对象 使用
            //BPGraphics graphics = createGraphics();
            BPGraphics graphics = element.createGraphics(BPApplication.singleton().activeDocument.viewManager.getActivedViewport().targetModel);
            

#if false
            graphics.addSolid(IGeSolidBase.createBox(box));
#elif true
            graphics.addSolid(IGeSolidBase.createExtrusion(extrusioninfo));

#endif
            graphics.save();

            return true;
        }

        private List<GeCurveArray> createListCurveAarry()
        {
            List<GeCurveArray> list = new List<GeCurveArray>();

            // 上
            GePoint3d uprightpoint = new GePoint3d(m_centertop);
            uprightpoint.x += m_toplargth / 2;
            uprightpoint.y -= m_topwidth / 2;
            uprightpoint.z += m_height / 2;

            GePoint3d upleftpoint = new GePoint3d(m_centertop);
            upleftpoint.x -= m_toplargth / 2;
            upleftpoint.y += m_topwidth / 2;
            upleftpoint.z += m_height / 2;


           GeCurveArray array =  GeCurveArray.createRectangle(uprightpoint.x, uprightpoint.y, 
                upleftpoint.x, upleftpoint.y, upleftpoint.z, GeCurveArray.BoundaryType.Inner);

            list.Add(array);


            return list;
        }

        private BPGraphics createGraphics()
        {
            BPViewport viewport = BPApplication.singleton()
                .activeDocument
                .viewManager
                .getActivedViewport();
            BPGraphics graphics = new BPGraphics(viewport.targetModel);


            return graphics;
        }

        public override bool onRightClick(BPCommandContext context)
        {
            if (null == context.mousePoint)
            {
                BPMessageCenter.sendMessage("鼠标位置获取失败");

                return false;
            }  



            return base.onRightClick(context);
        }
    }


    // 使用拉伸体必须继承BPGraphicsElemt类 必须重写_createGraphicsPoint类

    [BPExternalCommand(name ="cct2")]
    public class CCTest15 : IBPFunctionCommand
    {
        public override void onExcute(BPCommandContext context)
        {
            List<BPGraphics> list = new List<BPGraphics>();
            //graphics.save();
            //list.Add(graphics);
            BPGraphicElement elem = new CGraphicStrain(context.mousePoint);

            elem.addToDocument(BPApplication.singleton().activeDocument.viewManager.getActivedViewport().targetModel);
            BPGraphics graphics = new BPGraphics(BPApplication.singleton().activeDocument.viewManager.getActivedViewport().targetModel);
            

        }
    }


    public class CGraphicStrain : BPGraphicElement
    {
        GePoint3d m_centertop;
        GePoint3d m_centerbox;

        
        int mLength = 20;
        int mWidth = 20;
        int mHeight = 20;

        BPPlacement m_placement;
        public CGraphicStrain(GePoint3d point)
        {
            m_centertop = point;
        }

        protected override BPGraphics _createGraphics(BPModel model)
        {
            BPGraphics graphics = new BPGraphics(model);

            List<GePoint3d> listpoints = new List<GePoint3d>();
            listpoints.Add(new GePoint3d(0, 0, 0));
            listpoints.Add(new GePoint3d(mLength, 0, 0));
            listpoints.Add(new GePoint3d(mLength, mWidth, 0));
            listpoints.Add(new GePoint3d(0, mWidth, 0));
            listpoints.Add(new GePoint3d(0, 0, 0));

            GeCurveArray curvearray = GeCurveArray.createLinestringArray(listpoints,
                GeCurveArray.BoundaryType.Outer, false);

            GeVec3d vec = new GeVec3d(0, 0, mHeight);
            GeExtrusionInfo extrusionInfo = new GeExtrusionInfo(curvearray, vec, true);
            IGeSolidBase solid = IGeSolidBase.createExtrusion(extrusionInfo);
            graphics.addSolid(solid);

            return graphics;
        }

        protected override List<GePoint3d> _createGripPoints()
        {
            GeTransform transform = getPlacement().toTransform();

            List<GePoint3d> listptr = new List<GePoint3d>();
            // bottom
            listptr.Add(GePoint3d.createByTransform(transform, new GePoint3d(mLength / 2, mWidth / 2, 0)));
            // top
            listptr.Add(GePoint3d.createByTransform(transform, new GePoint3d(mLength / 2, mWidth / 2, mHeight)));
            // front
            listptr.Add(GePoint3d.createByTransform(transform, new GePoint3d(mLength / 2, 0, mHeight / 2)));
            // back
            listptr.Add(GePoint3d.createByTransform(transform, new GePoint3d(mLength / 2, mWidth, mHeight / 2)));
            // right
            listptr.Add(GePoint3d.createByTransform(transform, new GePoint3d(mLength, mWidth / 2, mHeight / 2)));
            // left
            listptr.Add(GePoint3d.createByTransform(transform, new GePoint3d(0, mWidth / 2, mHeight / 2)));
            return listptr;
        }

        protected override void _dragGripPoints(uint index, GePoint3d grippt, GePoint3d msPos)
        {

            // 创建变换矩阵
            GeTransform transf = GeTransform.create(m_centerbox);

            // 位置类
            BPPlacement placement = new BPPlacement();

            // 将该变化矩阵的matrix部分设置为单位矩阵
            GeTransform trans = GeTransform.createIdentityMatrix();

            switch(index)
            {
                case 0:
                    mHeight = mHeight + (int)(grippt.z - msPos.z);
                    trans = GeTransform.create(new GePoint3d(0, 0, msPos.z - grippt.z));
                    placement.fromTransform(GeTransform.createByProduct(trans, transf));
                    this.placement = placement;
                    break;

                case 1:
                    break;

                case 2:
                    break;

                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
            }



            #region abandon
            // 拖拽前的点的位置
            GePoint3d beforecenterpoint = new GePoint3d(m_centertop);
            // 拖拽后点的位置
            GePoint3d aftercenterpoint = new GePoint3d(m_centertop);
            aftercenterpoint.z += 10;
            #endregion
        }

        

        /// <summary>
        /// 获取位置
        /// </summary>
        /// <returns></returns>
        protected BPPlacement getPlacement()
        {
            BPPlacement placement = new BPPlacement();
            return placement;
        }
    }

    #endregion

    #region 注销命令类 2023已不支持

    [Obsolete("bimbase 2023 R1.0 已删除")]
    [BPExternalCommand(name = "shutdownribbon")]
    public class CCShutdowRibbon : IBPFunctionCommand
    {
        public override void onExcute(BPCommandContext context)
        {
            
        }
    }

#endregion


}
