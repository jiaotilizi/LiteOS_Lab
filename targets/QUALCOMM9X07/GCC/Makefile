##########################################################################################################################
#GCC compiler Makefile and compile it to libHuaweLiteOS.so
##########################################################################################################################

# ------------------------------------------------
# Generic Makefile (based on gcc)
# ------------------------------------------------

######################################
# target
######################################
TARGET = libHuawei_LiteOS
######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -O0 -g


#######################################
# binaries
#######################################
ifeq ($(CC), )
	PREFIX    = arm-oe-linux-gnueabi-
    CC        = $(PREFIX)gcc
    AS        = $(PREFIX)gcc -x assembler-with-cpp
    OBJCOPY   = $(PREFIX)objcopy
    OBJDUMP   = $(PREFIX)objdump
    AR        = $(PREFIX)ar
    SZ        = $(PREFIX)size
    LD        = $(PREFIX)ld
    HEX       = $(OBJCOPY) -O ihex
    BIN       = $(OBJCOPY) -O binary -S
endif

PROJECTBASE = $(abspath $(CURDIR))
TOP_DIR     = $(abspath $(PROJECTBASE)/../../..)

#this is for IoT Studio automatic generating kconfig compatibility
ifndef SDK_DIR
    SDK_DIR=$(abspath $(PROJECTBASE)/../../..)
endif

#######################################
# paths
#######################################
# firmware library path
PERIFLIB_PATH =

# Build path
BUILD_DIR = build

######################################
#common variables for other module or components
C_SOURCES =
C_DEFS = 
C_INCLUDES =
LDFLAGS =
ASM_SOURCES_S =
AS_DEFS =
AS_INCLUDES =
PERIFLIB_SOURCES =


##########################LOAD THE SOURCES INCLUDES AND DEFINES################
include ../.config
include $(TOP_DIR)/iot_link/iot.mk
include ./project.mk


######################################
# firmware library
######################################



#######################################
# CFLAGS
#######################################
# compile gcc flags
ASFLAGS =  $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS =  $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif

# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$@"

# excluded unnecessary warnings
CFLAGS += -Wno-missing-braces

#######################################
# LDFLAGS
#######################################

# libraries
LIBS = -lc -lm -lpthread -lrt
LDFLAGS = $(LIBS)


TARGET_DIR = $(BUILD_DIR)
############HERE WE GET THE C_OBJECT S_OBJECT AND THE PATH #####################

C_OBJ := $(C_SOURCES:$(TOP_DIR)/%.c=$(TARGET_DIR)/%.o)
OBJ_DIRS +=  $(dir $(C_OBJ))
S_OBJ := $(ASM_SOURCES_S:$(TOP_DIR)/%.S=$(TARGET_DIR)/%.o)
OBJ_DIRS +=  $(dir $(S_OBJ))
OBJ_DIRS := $(sort $(OBJ_DIRS))

##################DO THE BUILDING NOW###########################################
# default action: build all
all:$(TARGET_DIR)/$(TARGET).so

$(TARGET_DIR)/$(TARGET).so:$(OBJ_DIRS) $(C_OBJ) $(S_OBJ)
	$(CC) $(C_OBJ) $(S_OBJ) $(LDFLAGS) -fPIC -shared -o $@	
		
#create the necessary path for the object
$(OBJ_DIRS):
	-mkdir -p $@

#compile the c file to the object, as you know we has map the .c to the .o	
$(C_OBJ):$(TARGET_DIR)/%.o:$(TOP_DIR)/%.c
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(@:%.o=%.lst) $< -o $@ -fPIC

#compile the s fike to the object, as you know we has map the .S to the .o
$(S_OBJ):$(TARGET_DIR)/%.o:$(TOP_DIR)/%.S
	$(AS) -c $(CFLAGS) $< -o $@ -fPIC
		
 
################################################################################
# clean up
################################################################################
clean:
	-rm -fR .dep $(TARGET_DIR)

# *** EOF ***
