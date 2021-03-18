#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/contalitri.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/contalitri.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../main.c ../display.c ../peripherals.c "../DEE Emulation 16-bit/Flash Operations.s" "../DEE Emulation 16-bit/DEE Emulation 16-bit.c" ../timers.c ../lowvoltagesave.c ../adc.c ../sleep.c ../pwmBacklight.c ../pageFactory.c ../callbacks.c ../displayDriver.c ../flowMeter.c ../clock.c ../keyboard.c ../parameterStore.c ../wdt.c ../traps.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/display.o ${OBJECTDIR}/_ext/1472/peripherals.o "${OBJECTDIR}/_ext/869223802/Flash Operations.o" "${OBJECTDIR}/_ext/869223802/DEE Emulation 16-bit.o" ${OBJECTDIR}/_ext/1472/timers.o ${OBJECTDIR}/_ext/1472/lowvoltagesave.o ${OBJECTDIR}/_ext/1472/adc.o ${OBJECTDIR}/_ext/1472/sleep.o ${OBJECTDIR}/_ext/1472/pwmBacklight.o ${OBJECTDIR}/_ext/1472/pageFactory.o ${OBJECTDIR}/_ext/1472/callbacks.o ${OBJECTDIR}/_ext/1472/displayDriver.o ${OBJECTDIR}/_ext/1472/flowMeter.o ${OBJECTDIR}/_ext/1472/clock.o ${OBJECTDIR}/_ext/1472/keyboard.o ${OBJECTDIR}/_ext/1472/parameterStore.o ${OBJECTDIR}/_ext/1472/wdt.o ${OBJECTDIR}/_ext/1472/traps.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/1472/display.o.d ${OBJECTDIR}/_ext/1472/peripherals.o.d "${OBJECTDIR}/_ext/869223802/Flash Operations.o.d" "${OBJECTDIR}/_ext/869223802/DEE Emulation 16-bit.o.d" ${OBJECTDIR}/_ext/1472/timers.o.d ${OBJECTDIR}/_ext/1472/lowvoltagesave.o.d ${OBJECTDIR}/_ext/1472/adc.o.d ${OBJECTDIR}/_ext/1472/sleep.o.d ${OBJECTDIR}/_ext/1472/pwmBacklight.o.d ${OBJECTDIR}/_ext/1472/pageFactory.o.d ${OBJECTDIR}/_ext/1472/callbacks.o.d ${OBJECTDIR}/_ext/1472/displayDriver.o.d ${OBJECTDIR}/_ext/1472/flowMeter.o.d ${OBJECTDIR}/_ext/1472/clock.o.d ${OBJECTDIR}/_ext/1472/keyboard.o.d ${OBJECTDIR}/_ext/1472/parameterStore.o.d ${OBJECTDIR}/_ext/1472/wdt.o.d ${OBJECTDIR}/_ext/1472/traps.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/display.o ${OBJECTDIR}/_ext/1472/peripherals.o ${OBJECTDIR}/_ext/869223802/Flash\ Operations.o ${OBJECTDIR}/_ext/869223802/DEE\ Emulation\ 16-bit.o ${OBJECTDIR}/_ext/1472/timers.o ${OBJECTDIR}/_ext/1472/lowvoltagesave.o ${OBJECTDIR}/_ext/1472/adc.o ${OBJECTDIR}/_ext/1472/sleep.o ${OBJECTDIR}/_ext/1472/pwmBacklight.o ${OBJECTDIR}/_ext/1472/pageFactory.o ${OBJECTDIR}/_ext/1472/callbacks.o ${OBJECTDIR}/_ext/1472/displayDriver.o ${OBJECTDIR}/_ext/1472/flowMeter.o ${OBJECTDIR}/_ext/1472/clock.o ${OBJECTDIR}/_ext/1472/keyboard.o ${OBJECTDIR}/_ext/1472/parameterStore.o ${OBJECTDIR}/_ext/1472/wdt.o ${OBJECTDIR}/_ext/1472/traps.o

# Source Files
SOURCEFILES=../main.c ../display.c ../peripherals.c ../DEE Emulation 16-bit/Flash Operations.s ../DEE Emulation 16-bit/DEE Emulation 16-bit.c ../timers.c ../lowvoltagesave.c ../adc.c ../sleep.c ../pwmBacklight.c ../pageFactory.c ../callbacks.c ../displayDriver.c ../flowMeter.c ../clock.c ../keyboard.c ../parameterStore.c ../wdt.c ../traps.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/contalitri.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA306
MP_LINKER_FILE_OPTION=,--script=p24FJ128GA306.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main.c  -o ${OBJECTDIR}/_ext/1472/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/display.o: ../display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/display.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/display.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../display.c  -o ${OBJECTDIR}/_ext/1472/display.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/display.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/display.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/peripherals.o: ../peripherals.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/peripherals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/peripherals.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals.c  -o ${OBJECTDIR}/_ext/1472/peripherals.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/peripherals.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/peripherals.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/869223802/DEE\ Emulation\ 16-bit.o: ../DEE\ Emulation\ 16-bit/DEE\ Emulation\ 16-bit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869223802" 
	@${RM} "${OBJECTDIR}/_ext/869223802/DEE Emulation 16-bit.o".d 
	@${RM} "${OBJECTDIR}/_ext/869223802/DEE Emulation 16-bit.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../DEE Emulation 16-bit/DEE Emulation 16-bit.c"  -o "${OBJECTDIR}/_ext/869223802/DEE Emulation 16-bit.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/869223802/DEE Emulation 16-bit.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/869223802/DEE Emulation 16-bit.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/timers.o: ../timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../timers.c  -o ${OBJECTDIR}/_ext/1472/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/timers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/timers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/lowvoltagesave.o: ../lowvoltagesave.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/lowvoltagesave.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/lowvoltagesave.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../lowvoltagesave.c  -o ${OBJECTDIR}/_ext/1472/lowvoltagesave.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/lowvoltagesave.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/lowvoltagesave.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/adc.o: ../adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../adc.c  -o ${OBJECTDIR}/_ext/1472/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/sleep.o: ../sleep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/sleep.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/sleep.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sleep.c  -o ${OBJECTDIR}/_ext/1472/sleep.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/sleep.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/sleep.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/pwmBacklight.o: ../pwmBacklight.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/pwmBacklight.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/pwmBacklight.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pwmBacklight.c  -o ${OBJECTDIR}/_ext/1472/pwmBacklight.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/pwmBacklight.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/pwmBacklight.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/pageFactory.o: ../pageFactory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/pageFactory.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/pageFactory.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pageFactory.c  -o ${OBJECTDIR}/_ext/1472/pageFactory.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/pageFactory.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/pageFactory.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/callbacks.o: ../callbacks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/callbacks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/callbacks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../callbacks.c  -o ${OBJECTDIR}/_ext/1472/callbacks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/callbacks.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/callbacks.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/displayDriver.o: ../displayDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/displayDriver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/displayDriver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../displayDriver.c  -o ${OBJECTDIR}/_ext/1472/displayDriver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/displayDriver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/displayDriver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/flowMeter.o: ../flowMeter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/flowMeter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/flowMeter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../flowMeter.c  -o ${OBJECTDIR}/_ext/1472/flowMeter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/flowMeter.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/flowMeter.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/clock.o: ../clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../clock.c  -o ${OBJECTDIR}/_ext/1472/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/clock.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/clock.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/keyboard.o: ../keyboard.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/keyboard.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/keyboard.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../keyboard.c  -o ${OBJECTDIR}/_ext/1472/keyboard.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/keyboard.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/keyboard.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/parameterStore.o: ../parameterStore.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/parameterStore.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/parameterStore.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../parameterStore.c  -o ${OBJECTDIR}/_ext/1472/parameterStore.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/parameterStore.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/parameterStore.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/wdt.o: ../wdt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/wdt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../wdt.c  -o ${OBJECTDIR}/_ext/1472/wdt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/wdt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/wdt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/traps.o: ../traps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../traps.c  -o ${OBJECTDIR}/_ext/1472/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/traps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main.c  -o ${OBJECTDIR}/_ext/1472/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/display.o: ../display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/display.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/display.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../display.c  -o ${OBJECTDIR}/_ext/1472/display.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/display.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/display.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/peripherals.o: ../peripherals.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/peripherals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/peripherals.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals.c  -o ${OBJECTDIR}/_ext/1472/peripherals.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/peripherals.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/peripherals.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/869223802/DEE\ Emulation\ 16-bit.o: ../DEE\ Emulation\ 16-bit/DEE\ Emulation\ 16-bit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869223802" 
	@${RM} "${OBJECTDIR}/_ext/869223802/DEE Emulation 16-bit.o".d 
	@${RM} "${OBJECTDIR}/_ext/869223802/DEE Emulation 16-bit.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../DEE Emulation 16-bit/DEE Emulation 16-bit.c"  -o "${OBJECTDIR}/_ext/869223802/DEE Emulation 16-bit.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/869223802/DEE Emulation 16-bit.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/869223802/DEE Emulation 16-bit.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/timers.o: ../timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../timers.c  -o ${OBJECTDIR}/_ext/1472/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/timers.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/timers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/lowvoltagesave.o: ../lowvoltagesave.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/lowvoltagesave.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/lowvoltagesave.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../lowvoltagesave.c  -o ${OBJECTDIR}/_ext/1472/lowvoltagesave.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/lowvoltagesave.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/lowvoltagesave.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/adc.o: ../adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../adc.c  -o ${OBJECTDIR}/_ext/1472/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/sleep.o: ../sleep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/sleep.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/sleep.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sleep.c  -o ${OBJECTDIR}/_ext/1472/sleep.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/sleep.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/sleep.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/pwmBacklight.o: ../pwmBacklight.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/pwmBacklight.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/pwmBacklight.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pwmBacklight.c  -o ${OBJECTDIR}/_ext/1472/pwmBacklight.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/pwmBacklight.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/pwmBacklight.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/pageFactory.o: ../pageFactory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/pageFactory.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/pageFactory.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pageFactory.c  -o ${OBJECTDIR}/_ext/1472/pageFactory.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/pageFactory.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/pageFactory.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/callbacks.o: ../callbacks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/callbacks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/callbacks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../callbacks.c  -o ${OBJECTDIR}/_ext/1472/callbacks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/callbacks.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/callbacks.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/displayDriver.o: ../displayDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/displayDriver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/displayDriver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../displayDriver.c  -o ${OBJECTDIR}/_ext/1472/displayDriver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/displayDriver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/displayDriver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/flowMeter.o: ../flowMeter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/flowMeter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/flowMeter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../flowMeter.c  -o ${OBJECTDIR}/_ext/1472/flowMeter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/flowMeter.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/flowMeter.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/clock.o: ../clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../clock.c  -o ${OBJECTDIR}/_ext/1472/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/clock.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/keyboard.o: ../keyboard.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/keyboard.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/keyboard.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../keyboard.c  -o ${OBJECTDIR}/_ext/1472/keyboard.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/keyboard.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/keyboard.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/parameterStore.o: ../parameterStore.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/parameterStore.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/parameterStore.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../parameterStore.c  -o ${OBJECTDIR}/_ext/1472/parameterStore.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/parameterStore.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/parameterStore.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/wdt.o: ../wdt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/wdt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../wdt.c  -o ${OBJECTDIR}/_ext/1472/wdt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/wdt.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/wdt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/traps.o: ../traps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../traps.c  -o ${OBJECTDIR}/_ext/1472/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-data -mconst-in-code -O0 -msmart-io=1 -msfr-warn=off   -msmart-io=0  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/traps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/869223802/Flash\ Operations.o: ../DEE\ Emulation\ 16-bit/Flash\ Operations.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869223802" 
	@${RM} "${OBJECTDIR}/_ext/869223802/Flash Operations.o".d 
	@${RM} "${OBJECTDIR}/_ext/869223802/Flash Operations.o" 
	${MP_CC} $(MP_EXTRA_AS_PRE)  "../DEE Emulation 16-bit/Flash Operations.s"  -o "${OBJECTDIR}/_ext/869223802/Flash Operations.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/869223802/Flash Operations.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/869223802/Flash Operations.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/869223802/Flash\ Operations.o: ../DEE\ Emulation\ 16-bit/Flash\ Operations.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/869223802" 
	@${RM} "${OBJECTDIR}/_ext/869223802/Flash Operations.o".d 
	@${RM} "${OBJECTDIR}/_ext/869223802/Flash Operations.o" 
	${MP_CC} $(MP_EXTRA_AS_PRE)  "../DEE Emulation 16-bit/Flash Operations.s"  -o "${OBJECTDIR}/_ext/869223802/Flash Operations.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/869223802/Flash Operations.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/_ext/869223802/Flash Operations.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/contalitri.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/contalitri.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_ICD3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp=${DFP_DIR}/xc16 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/contalitri.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/contalitri.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp=${DFP_DIR}/xc16 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/contalitri.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp=${DFP_DIR}/xc16 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
