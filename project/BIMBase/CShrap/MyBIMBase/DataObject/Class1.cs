using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using BIMBaseCS.ApplicationService;
using BIMBaseCS.Attributes;
using BIMBaseCS.Core;
using BIMBaseCS.Data;
using BIMBaseCS.Geometry;
namespace DataObject
{
    [BPElementClass(schemaName = "TestSchema", className = "CubeTest")]
    public class CCube : BPGraphicElement
    {
        int m_iLength = 2000;
        int m_iWidth = 1500;
        int m_iHeight = 3000;

        [BPPropertyDefinition(fieldName ="Width")]
        public int Width
        {
            get
            {
                return m_iWidth;
            }
            set
            {
                m_iWidth = value;
            }
        }

        [BPPropertyDefinition(fieldName ="Height")]
        public int Height
        {
            get
            {
                return m_iHeight;
            }
            set
            {
                m_iHeight = value;
            }
        }

        [BPPropertyDefinition(fieldName ="Length")]
        public int Length
        {
            get
            {
                return m_iLength;
            }
            set
            {
                m_iLength = value;
            }
        }

        /// <summary>
        /// 造型绘制
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
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
            listPt.Add(new GePoint3d(m_iLength , m_iWidth / 2, m_iHeight / 2));

            return listPt;
        }

        protected override void _dragGripPoints(uint index, GePoint3d grippt, GePoint3d msPos)
        {
            GeTransform transform = GeTransform.create(new GePoint3d(m_iLength, m_iWidth, m_iHeight));
            // 该类封装图形构件的位置信息。
            BPPlacement placement = new BPPlacement();
            // 创建变换矩阵的matrix部分为单位矩阵
            GeTransform trans = GeTransform.createIdentityMatrix();

            switch(index)
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
}
