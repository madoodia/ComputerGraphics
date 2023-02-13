/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include "maya/MFnPlugin.h"
#include "maya/MGlobal.h"
#include "maya/MIOStream.h"
#include "maya/MString.h"
#include "maya/MStatus.h"
#include "maya/MTypeId.h"

#include "maya/MFnNumericAttribute.h"
#include "maya/MFnTypedAttribute.h"
#include "maya/MFnUnitAttribute.h"
#include "maya/MFnMatrixAttribute.h"
#include "maya/MFnCompoundAttribute.h"
#include "maya/MFnEnumAttribute.h"
#include "maya/MFnMessageAttribute.h"
#include "maya/MFnMesh.h"
#include "maya/MFnMeshData.h"

class MyNode : public MPxNode
{
public:
  MyNode();
  virtual ~MyNode();
  static void* creator();
  static MStatus initialize();

  virtual MStatus compute(const MPlug& plug, MDataBlock& data);

  static MTypeId id;
  static MObject inputMesh;
  static MObject outputMesh;
};

MTypeId MyNode::id(0x00000001);
MObject MyNode::inputMesh;
MObject MyNode::outputMesh;

MyNode::MyNode() {}
MyNode::~MyNode() {}

void* MyNode::creator()
{
  return new MyNode();
}

MStatus MyNode::initialize()
{
  MFnTypedAttribute tAttr;
  MFnMeshData meshData;

  inputMesh = tAttr.create("inputMesh", "in", MFnData::kMesh, meshData.create());
  tAttr.setStorable(false);
  tAttr.setWritable(true);
  tAttr.setReadable(false);
  tAttr.setHidden(false);
  tAttr.setKeyable(false);
  tAttr.setConnectable(true);
  tAttr.setDisconnectBehavior(MFnAttribute::kDelete);
  tAttr.setCached(false);
  tAttr.setArray(false);
  tAttr.setUsesArrayDataBuilder(false);
  tAttr.setIndexMatters(false);
  tAttr.setChannelBox(false);
  tAttr.setAffectsAppearance(false);
  tAttr.setAffectsWorldSpace(false);
  tAttr.setAffectsWorldSpaceGeometry(false);
  tAttr.setAffectsWorldSpaceLighting(false);
  tAttr.setAffectsWorldSpaceMotionBlur(false);
  tAttr.setAffectsWorldSpaceShadows(false);
  tAttr.setAffectsWorldSpaceReflections(false);
  tAttr.setAffectsWorldSpaceRefractions(false);
  tAttr.setAffectsWorldSpaceSubdivSurface(false);

  outputMesh = tAttr.create("outputMesh", "out", MFnData::kMesh, meshData.create());
  tAttr.setStorable(false);
  tAttr.setWritable(false);
  tAttr.setReadable(true);
  tAttr.setHidden(false);

  addAttribute(inputMesh);
  addAttribute(outputMesh);

  attributeAffects(inputMesh, outputMesh);

  return MS::kSuccess;
}

MStatus MyNode::compute(const MPlug& plug, MDataBlock& data)
{
  MStatus status;

  if (plug == outputMesh)
  {
    MDataHandle inputData = data.inputValue(inputMesh, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);

    MFnMesh inputMeshFn(inputData.data(), &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);

    MDataHandle outputData = data.outputValue(outputMesh, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);

    MFnMesh outputMeshFn;
    outputMeshFn.create(inputMeshFn.numVertices(), inputMeshFn.numPolygons(), inputMeshFn.numFaceVertices(), inputMeshFn.numEdges(), inputMeshFn.numFaceVertices(), inputMeshFn.numFaceVertices(), outputData.data(), &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);

    MPointArray points;
    inputMeshFn.getPoints(points, MSpace::kObject);
    outputMeshFn.setPoints(points, MSpace::kObject);

    MIntArray faceCounts;
    inputMeshFn.getPolygonCounts(faceCounts);
    outputMeshFn.setPolygonCounts(faceCounts);

    MIntArray faceConnects;
    inputMeshFn.getPolygonVertices(faceConnects);
    outputMeshFn.setPolygonVertices(faceConnects);

    outputData.setClean();
  }
  else
  {
    return MS::kUnknownParameter;
  }

  return MS::kSuccess;
}

MStatus initializePlugin(MObject obj)
{
  MStatus status;
  MFnPlugin plugin(obj, "madoodia.com", "1.0", "Any");

  status = plugin.registerNode("MyNode", MyNode::id, MyNode::creator, MyNode::initialize, MPxNode::kDependNode);
  CHECK_MSTATUS_AND_RETURN_IT(status);

  return status;
}

MStatus uninitializePlugin(MObject obj)
{
  MStatus status;
  MFnPlugin plugin(obj);

  status = plugin.deregisterNode(MyNode::id);
  CHECK_MSTATUS_AND_RETURN_IT(status);

  return status;
}
