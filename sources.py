"""
Lists the source code files that make up Mario Kart Wii.
"""


from dataclasses import dataclass
from itertools import chain


HOSTSYS_OPTS = ' -ipa file -rostr -str noreuse -use_lmw_stmw=on'
RVL_OPTS = ' -lang=c99 -ipa file'
MSL_LIBC_OPTS = ' -lang=c99 -ipa file'
NW4R_OPTS = ' -lang=c99 -ipa file -inline auto -O4,p -pragma \"legacy_struct_alignment on\"'
SPY_OPTS = RVL_OPTS + " -w nounusedexpr -w nounusedarg"
RFL_OPTS = RVL_OPTS + " -O4,p"
EGG_OPTS = ' -lang=c99 -use_lmw_stmw=on -ipa function -rostr'
REL_OPTS = HOSTSYS_OPTS + " -sdata 0 -sdata2 0 -lang=c++ -pragma \"legacy_struct_alignment on\" -DREL"


@dataclass
class Source:
    src: str
    cc: str
    opts: str


#
# main.dol
#

SOURCES_HOSTSYS = [
    Source(src="source/game/host_system/SystemResource.cpp", cc='4201_127', opts=HOSTSYS_OPTS),
    Source(src="source/game/host_system/RKSystem.cpp", cc='4201_127', opts=HOSTSYS_OPTS),
]

SOURCES_TRK = [
    Source(src="source/runtime/__mem.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/runtime/__start.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/runtime/__ppc_eabi_init.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_MSL_LIBC = [
    Source(src="source/platform/ansi_files.c", cc='4201_127', opts=MSL_LIBC_OPTS),
#    Source(src="source/platform/ansi_fp.c", cc='4201_127', opts=MSL_LIBC_OPTS),
    Source(src="source/platform/float.c", cc='4201_127', opts=MSL_LIBC_OPTS),
    Source(src="source/platform/mem.c", cc='4201_127', opts=MSL_LIBC_OPTS),
    Source(src="source/platform/mem_cpy.c", cc='4201_127', opts=MSL_LIBC_OPTS),
#    Source(src="source/platform/printf.c", cc='4201_127', opts=MSL_LIBC_OPTS),
    Source(src="source/platform/qsort.c", cc='4201_127', opts=MSL_LIBC_OPTS),
    Source(src="source/platform/rand.c", cc='4201_127', opts=MSL_LIBC_OPTS),
#    Source(src="source/platform/scanf.c", cc='4201_127', opts=MSL_LIBC_OPTS),
    Source(src="source/platform/wchar.c", cc='4201_127', opts=MSL_LIBC_OPTS),
    Source(src="source/platform/ExceptionPPC.cpp", cc='4201_127', opts=MSL_LIBC_OPTS),
    Source(src="source/platform/__init_cpp_exceptions.cpp", cc='4201_127', opts=MSL_LIBC_OPTS),
    Source(src="source/platform/va_arg.c", cc='4201_127', opts=MSL_LIBC_OPTS),
    Source(src="source/platform/eabi.c", cc='4201_127', opts=MSL_LIBC_OPTS),
    Source(src="source/platform/global_destructor_chain.c", cc='4201_127', opts=MSL_LIBC_OPTS),
]
SOURCES_RVL_ARC = [
    Source(src="source/rvl/arc/rvlArchive.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_AX = [
    Source(src="source/rvl/ax/rvlAx.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/ax/rvlAxAlloc.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/ax/rvlAxAux.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/ax/rvlAxCl.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/ax/rvlAxComp.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/ax/rvlAxDspCode.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/ax/rvlAxOut.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/ax/rvlAxSpb.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/ax/rvlAxVpb.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/ax/rvlAxProf.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_AXFX = [
    Source(src="source/rvl/axfx/rvlAxFxReverbHi.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/axfx/rvlAxFxReverbHiExp.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/axfx/rvlAxFxReverbHiExpDpl2.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/axfx/rvlAxFxReverbStdExp.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/axfx/rvlAxFx.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_BASE = [
    Source(src="source/rvl/base/ppcArch.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_BTE = [
    Source(src="source/rvl/bte/gki_buffer.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/gki_time.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/gki_ppc.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/hcisu_h2.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/uusb_ppc.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bte_hcisu.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bte_init.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bte_logmsg.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bte_main.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bte_task1.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bd.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bta_sys.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/ptim.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/utl.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bta_dm_int.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bta_api.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bta_dm_main.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/bte/bta_dm_pm.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bta_hh_act.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bta_hh_api.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/bte/bta_hh_main.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/bta_hh_utils.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/btm_acl.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/btm_dev.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/btm_devctl.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/btm_discovery.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/btm_inq.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/btm_main.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/btm_pm.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/btm_sco.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/btm_sec.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/btu_hcif.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/btu_init.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/wbt_ext.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/gap_api.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/gap_conn.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/bte/gap_utils.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/hcicmds.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/hidd_api.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/hidd_conn.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/hidd_mgmt.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/hidd_pm.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/hidh_api.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/hidh_conn.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/l2c_api.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/bte/l2c_csm.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/l2c_link.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/bte/l2c_main.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/l2c_utils.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/port_api.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/port_rfc.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/port_utils.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/rfc_l2cap_if.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/bte/rfc_mx_fsm.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/bte/rfc_port_fsm.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/rfc_port_if.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/rfc_ts_frames.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/rfc_utils.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/bte/sdp_api.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/sdp_db.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/bte/sdp_discovery.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/sdp_main.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/bte/sdp_server.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/bte/sdp_utils.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_CNT = [
    Source(src="source/rvl/cnt/cnt.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_CX = [
    Source(src="source/rvl/cx/cxStreamingUncompression.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/cx/cxUncompression.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_DARCH = [
    Source(src="source/rvl/darch/darch.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_DB = [
    Source(src="source/rvl/db/db.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/db/dbPrintf.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_DSP = [
    Source(src="source/rvl/dsp/dsp.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/dsp/dspPrintf.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/dsp/dspTask.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_DVD = [
    Source(src="source/rvl/dvd/dvdFs.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/dvd/dvdMain.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/dvd/dvdQueue.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/dvd/dvdError.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/dvd/dvdUtils.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/dvd/dvdFatal.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/dvd/dvdDeviceError.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/dvd/dvdBroadway.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_ENC = [
    Source(src="source/rvl/enc/encUtility.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_ESP = [
    Source(src="source/rvl/esp/esp.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_EUART = [
    Source(src="source/rvl/euart/euart.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_EXI = [
    Source(src="source/rvl/exi/exiBios.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/exi/exiUart.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/exi/exiCommon.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_FS = [
    Source(src="source/rvl/fs/fs.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_GX = [
    Source(src="source/rvl/gx/gxInit.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/gx/gxFifo.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/gx/gxAttr.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/gx/gxMisc.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/gx/gxGeometry.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/gx/gxFrameBuf.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/gx/gxLight.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/gx/gxTexture.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/gx/gxBump.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/gx/gxTev.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/gx/gxPixel.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/gx/gxDraw.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/gx/gxDisplayList.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/gx/gxTransform.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/gx/gxPerf.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_IPC = [
    Source(src="source/rvl/ipc/ipcclt.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/ipc/ipcMain.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_KPAD = [
    Source(src="source/rvl/kpad/rvlKpad.c", cc='4199_60831', opts=RVL_OPTS),
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
    Source(src="source/rvl/nand/rvlNand1.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/nand/rvlNand2.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/nand/rvlNand3.c", cc='4199_60831', opts=RVL_OPTS),
]
SOURCES_RVL_OS = [
    Source(src="source/rvl/os/osAlarm.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osAlloc.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osArena.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osAudio.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osCache.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osContext.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/os/osError.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osFatal.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osFont.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osInterrupt.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osLink.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/os/osMemory.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osMessage.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/os/osMutex.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osReboot.c", cc='4199_60831', opts=RVL_OPTS),
#    Source(src="source/rvl/os/osReset.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osRtc.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osSync.c", cc='4199_60831', opts=RVL_OPTS),
    Source(src="source/rvl/os/osThread.c", cc='4199_60831', opts=RVL_OPTS),
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
    Source(src="source/gamespy/GP/gp.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpi.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiBuddy.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiBuffer.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiCallback.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiConnect.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiInfo.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiKeys.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiOperation.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiPeer.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiProfile.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiSearch.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiTransfer.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiUnique.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/GP/gpiUtility.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Auth.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Buffer.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Callback.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Connection.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Main.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Socket.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/gt2/gt2Utility.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/qr2/qr2.c", cc='4199_60831', opts=SPY_OPTS),
    Source(src="source/gamespy/qr2/qr2regkeys.c", cc='4199_60831', opts=SPY_OPTS),
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
SOURCES_NW4R_LYT = [
    Source(src="source/nw4r/lyt/lyt_init.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/lyt/lyt_textBox.cpp", cc='4201_127', opts=NW4R_OPTS), # placeholder
]
SOURCES_NW4R_SND = [
    Source(src="source/nw4r/snd/snd_dvdSoundArchive.cpp", cc='4201_127', opts=NW4R_OPTS + " -func_align 16 "),
]
SOURCES_NW4R_UT = [
    Source(src="source/nw4r/ut/utList.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_LinkList.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_binaryFileFormat.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_CharStrmReader.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_charWriter.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_IOStream.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_fileStream.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_dvdFileStream.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_dvdLockedFileStream.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_nandFileStream.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_lockedCache.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_font.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_romFont.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_resFontBase.cpp", cc='4201_127', opts=NW4R_OPTS),
    Source(src="source/nw4r/ut/ut_resFont.cpp", cc='4201_127', opts=NW4R_OPTS),
]
SOURCES_RFL = [
    Source(src="source/rfl/rfl_init.c", cc='4201_127', opts=RFL_OPTS),
    Source(src="source/rfl/rfl_icon.c", cc='4201_127', opts=RFL_OPTS),
]
SOURCES_EGG_CORE = [
    Source(src="source/egg/core/eggAllocator.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggArchive.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggAsyncDisplay.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/util/eggCntFile.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggCompress.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggDecomp.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggDisplay.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggDisposer.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggDvdFile.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggDvdRipper.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggExpHeap.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/util/eggEffect.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/util/eggEffectCreator.cpp", cc='4201_127', opts=EGG_OPTS),
#    Source(src="source/egg/gfx/eggFog.cpp", cc='4201_127', opts=EGG_OPTS),
#    Source(src="source/egg/gfx/eggFogManager.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggGraphicsFifo.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggHeap.cpp", cc='4201_127', opts=EGG_OPTS + " -ipa file "),
    Source(src="source/egg/gfx/eggIScnProc.cpp", cc='4201_127', opts=EGG_OPTS),
#    Source(src="source/egg/gfx/eggLightManager.cpp", cc='4201_127', opts=EGG_OPTS),
#    Source(src="source/egg/gfx/eggLightObject.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggProcessMeter.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/util/eggSaveBanner.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggScene.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggSceneManager.cpp", cc='4201_127', opts=EGG_OPTS),
#    Source(src="source/egg/gfx/eggScnRenderer.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/util/eggStream.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggStreamDecomp.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggSystem.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggTextureBuffer.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggTaskThread.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggThread.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggUnitHeap.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggVideo.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggViewport.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggXfb.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/core/eggXfbManager.cpp", cc='4201_127', opts=EGG_OPTS),
#    Source(src="source/egg/core/g3d_scnrfl.cpp", cc='4201_127', opts=EGG_OPTS),
]
SOURCES_EGG_AUDIO = [
    Source(src="source/egg/audio/eggAudioArcPlayerMgr.cpp", cc='4201_127', opts=EGG_OPTS),
]
SOURCES_EGG_MATH = [
    Source(src="source/egg/math/eggQuat.cpp", cc='4201_127', opts=EGG_OPTS),
    Source(src="source/egg/math/eggVector.cpp", cc='4201_127', opts=EGG_OPTS),
]
SOURCES_DOL = list(chain(
    SOURCES_HOSTSYS,
    SOURCES_TRK,
    SOURCES_MSL_LIBC,
    SOURCES_RVL_ARC,
    SOURCES_RVL_AX,
    SOURCES_RVL_AXFX,
    SOURCES_RVL_BASE,
    SOURCES_RVL_BTE,
    SOURCES_RVL_CNT,
    SOURCES_RVL_CX,
    SOURCES_RVL_DARCH,
    SOURCES_RVL_DB,
    SOURCES_RVL_DSP,
    SOURCES_RVL_DVD,
    SOURCES_RVL_ENC,
    SOURCES_RVL_ESP,
    SOURCES_RVL_EUART,
    SOURCES_RVL_EXI,
    SOURCES_RVL_FS,
    SOURCES_RVL_GX,
    SOURCES_RVL_IPC,
    SOURCES_RVL_KPAD,
    SOURCES_RVL_MEM,
    SOURCES_RVL_MTX,
    SOURCES_RVL_NAND,
    SOURCES_RVL_OS,
    SOURCES_RVL_PAD,
    SOURCES_RVL_SI,
    SOURCES_RVL_TPL,
    SOURCES_RVL_SO,
    SOURCES_RVL_DWC,
    SOURCES_SPY,
    SOURCES_NW4R_MATH,
    SOURCES_NW4R_G3D,
    SOURCES_NW4R_LYT,
    SOURCES_NW4R_SND,
    SOURCES_NW4R_UT,
    SOURCES_RFL,
    SOURCES_EGG_CORE,
    SOURCES_EGG_AUDIO,
    SOURCES_EGG_MATH,
))

#
# StaticR.rel
#

SOURCES_REL = [
    Source(src="source/game/ui/MessageGroup.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/ui/ControlGroup.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/ui/UIControl.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/ui/Page.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/ui/Section.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/ui/SectionAutogens.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/ui/SectionDirector.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/CourseCheckpoints.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/CourseMap.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/DvdArchive.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/GhostFile.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/KPadController.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/KPadDirector.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/Mii.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/LocalizedArchive.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/MultiDvdArchive.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/NandUtil.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/Rating.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/RaceConfig.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/RaceManager.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/ResourceManager.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/system/ResourceManagerUnk80542868.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/util/ModuleSymbols.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/util/Random.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/kart/KartMove.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/kart/KartObjectProxy.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/geo/ObjKoopaFigure64.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/geo/ObjKuribo.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/geo/ObjFloat.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/geo/ObjOilSFC.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/geo/MapObjSniper.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/geo/ObjSound.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/geo/ObjSunDS.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/geo/ObjSunDSManager.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/geo/ObjTaimatsu.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/geo/BoxColManager.cpp", cc='4201_127', opts=REL_OPTS),
    Source(src="source/game/geo/BoxColUnit.cpp", cc='4201_127', opts=REL_OPTS),
]
