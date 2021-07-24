"""
Lists the source code files that make up Mario Kart Wii.
"""


from dataclasses import dataclass
from itertools import chain


RVL_OPTS = '-ipa file'
SPY_OPTS = RVL_OPTS + " -w nounusedexpr -w nounusedarg"
EGG_OPTS = '-ipa function -rostr'
REL_OPTS = '-ipa file -rostr -sdata 0 -sdata2 0'
NW4R_OPTS = '-ipa file -inline auto -rostr -O4,p'


@dataclass
class Source:
    src: str
    cc: str
    opts: str


#
# main.dol
#


SOURCES_TRK = [
    Source(src="source/rvl/trk/rvlTrkMem.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_ARC = [
    Source(src="source/rvl/arc/rvlArchive.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_MEM = [
    Source(src="source/rvl/mem/rvlMemHeap.cpp", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/mem/rvlMemExpHeap.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/mem/rvlMemFrmHeap.cpp", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/mem/rvlMemUnitHeap.cpp", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/mem/rvlMemAllocator.cpp", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/mem/rvlMemList.cpp", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_MTX = [
    Source(src="source/rvl/mtx/rvlMtx.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/mtx/rvlMtx2.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/mtx/rvlVec.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/mtx/rvlQuat.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_NAND = [
    Source(src="source/rvl/nand/nand.c", cc='4199_60831', opts=RVL_OPTS)
]
SOURCES_RVL_PAD = [
    Source(src="source/rvl/pad/rvlPadClamp.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/pad/rvlPad.c", cc='4199_60831', opts=RVL_OPTS + " -inline on,noauto "),
]
SOURCES_RVL_SI = [
    Source(src="source/rvl/si/siBios.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_TPL = [
    Source(src="source/rvl/tpl/tpl.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_SO = [
    Source(src="source/rvl/so/soCommon.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/so/soBasic.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_DWC = [
    Source(src="source/dwc/common/dwc_error.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_SPY = [
    Source(src="source/gamespy/darray.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/hashtable.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/md5c.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/common/revolution/gsSocketRevolution.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/common/gsAvailable.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/common/revolution/gsUtilRevolution.c", cc='4199_60831', opts=SPY_OPTS),
    # Source(src="source/gamespy/common/gsPlatformUtil.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/common/gsCore.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/common/gsUdpEngine.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/common/gsXML.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gp.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpi.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiBuddy.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiBuffer.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiCallback.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiConnect.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiInfo.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiKeys.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiOperation.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiPeer.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiProfile.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiSearch.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiTransfer.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiUnique.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gp/gpiUtility.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Auth.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Buffer.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Callback.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Connection.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Main.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Socket.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Utility.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/qr2/qr2.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/qr2/qr2RegKeys.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/ghttp/ghttpBuffer.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/ghttp/ghttpCallbacks.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/ghttp/ghttpCommon.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/ghttp/ghttpConnection.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/ghttp/ghttpEncryption.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/ghttp/ghttpMain.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/ghttp/ghttpPost.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/ghttp/ghttpProcess.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gstats/gbucket.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gstats/gstats.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/serverbrowsing/sb_crypt.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/serverbrowsing/sb_queryengine.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/serverbrowsing/sb_server.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/serverbrowsing/sb_serverlist.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/serverbrowsing/sb_serverbrowsing.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/sake/sakeMain.c", cc='4199_60831', opts=SPY_OPTS),
]
SOURCES_NW4R_MATH = [
    Source(src="source/nw4r/math/mathTriangular.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/math/mathTypes.cpp", cc='4201_127', opts=NW4R_OPTS),
]
SOURCES_NW4R_G3D = [
    Source(src="source/nw4r/g3d/g3d_camera.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/g3d/g3d_fog.cpp", cc='4201_127', opts=NW4R_OPTS),
]
SOURCES_NW4R_UT = [
    Source(src="source/nw4r/ut/utList.cpp", cc='4201_127', opts=NW4R_OPTS),
]
SOURCES_EGG_CORE = [
    Source(src="source/egg/core/eggAllocator.cpp", cc='4201_127', opts=EGG_OPTS + " -use_lmw_stmw=on "),
    Source(src="source/egg/core/eggArchive.cpp", cc='4201_127', opts=EGG_OPTS + " -use_lmw_stmw=on "),
    Source(src="source/egg/core/eggDisposer.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggExpHeap.cpp", cc='4201_127', opts=EGG_OPTS + " -use_lmw_stmw=on  "),
    Source(src="source/egg/core/eggGraphicsFifo.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggHeap.cpp", cc='4201_127', opts=EGG_OPTS + " -ipa file -use_lmw_stmw=on  "),
    Source(src="source/egg/core/eggStreamDecomp.cpp", cc='4201_127', opts=EGG_OPTS),
    # Source(src="source/egg/core/eggSystem.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggThread.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggUnitHeap.cpp", cc='4201_127', opts=EGG_OPTS + " -use_lmw_stmw=on  "),
    Source(src="source/egg/core/eggVideo.cpp", cc='4201_127', opts=EGG_OPTS+ " -use_lmw_stmw=on  "),
    # Source(src="source/egg/core/eggXfb.cpp", cc='4201_127', opts=EGG_OPTS),
    # Source(src="source/egg/core/eggXfbManager.cpp", cc='4201_127', opts=EGG_OPTS),
]
SOURCES_EGG_MATH = [
    Source(src="source/egg/math/eggQuat.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/math/eggVector.cpp", cc='4201_127', opts=EGG_OPTS),
]
SOURCES_DOL = list(chain(
    SOURCES_TRK,
    SOURCES_RVL_ARC,
    SOURCES_RVL_MEM,
    SOURCES_RVL_MTX,
    SOURCES_RVL_NAND,
    SOURCES_RVL_PAD,
    SOURCES_RVL_SI,
    SOURCES_RVL_TPL,
    SOURCES_RVL_SO,
    SOURCES_RVL_DWC,
    SOURCES_SPY,
    SOURCES_NW4R_MATH,
    SOURCES_NW4R_G3D,
    SOURCES_NW4R_UT,
    SOURCES_EGG_CORE,
    SOURCES_EGG_MATH,
))

#
# StaticR.rel
#

SOURCES_REL = [
    Source(src="source/game/ui/MessageGroup.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/ui/ControlGroup.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/ui/UIControl.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/jmap/JmpResourceCourse.cpp", cc='4201_127', opts=REL_OPTS),
]
