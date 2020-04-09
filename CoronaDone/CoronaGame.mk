##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CoronaGame
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/Thomas/Documents/Wumpus
ProjectPath            :=C:/Users/Thomas/Documents/Wumpus/CoronaGame
IntermediateDirectory  :=../build-$(ConfigurationName)/CoronaGame
OutDir                 :=../build-$(ConfigurationName)/CoronaGame
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Thomas
Date                   :=09/04/2020
CodeLitePath           :=F:/CodeLite
LinkerName             :=C:/TDM-GCC-32/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-32/bin/ar.exe rcu
CXX      := C:/TDM-GCC-32/bin/g++.exe
CC       := C:/TDM-GCC-32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=F:\CodeLite
Objects0=../build-$(ConfigurationName)/CoronaGame/GameFunctions.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CoronaGame/Roomcheck.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CoronaGame/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CoronaGame/ComputerAI.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CoronaGame/WriteRead.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CoronaGame/Play.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CoronaGame/Instructions.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/CoronaGame/GenerateMap.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/CoronaGame/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\CoronaGame" mkdir "..\build-$(ConfigurationName)\CoronaGame"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\CoronaGame" mkdir "..\build-$(ConfigurationName)\CoronaGame"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/CoronaGame/.d:
	@if not exist "..\build-$(ConfigurationName)\CoronaGame" mkdir "..\build-$(ConfigurationName)\CoronaGame"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/CoronaGame/GameFunctions.cpp$(ObjectSuffix): GameFunctions.cpp ../build-$(ConfigurationName)/CoronaGame/GameFunctions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thomas/Documents/Wumpus/CoronaGame/GameFunctions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameFunctions.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CoronaGame/GameFunctions.cpp$(DependSuffix): GameFunctions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CoronaGame/GameFunctions.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CoronaGame/GameFunctions.cpp$(DependSuffix) -MM GameFunctions.cpp

../build-$(ConfigurationName)/CoronaGame/GameFunctions.cpp$(PreprocessSuffix): GameFunctions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CoronaGame/GameFunctions.cpp$(PreprocessSuffix) GameFunctions.cpp

../build-$(ConfigurationName)/CoronaGame/Roomcheck.cpp$(ObjectSuffix): Roomcheck.cpp ../build-$(ConfigurationName)/CoronaGame/Roomcheck.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thomas/Documents/Wumpus/CoronaGame/Roomcheck.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Roomcheck.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CoronaGame/Roomcheck.cpp$(DependSuffix): Roomcheck.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CoronaGame/Roomcheck.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CoronaGame/Roomcheck.cpp$(DependSuffix) -MM Roomcheck.cpp

../build-$(ConfigurationName)/CoronaGame/Roomcheck.cpp$(PreprocessSuffix): Roomcheck.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CoronaGame/Roomcheck.cpp$(PreprocessSuffix) Roomcheck.cpp

../build-$(ConfigurationName)/CoronaGame/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/CoronaGame/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thomas/Documents/Wumpus/CoronaGame/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CoronaGame/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CoronaGame/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CoronaGame/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/CoronaGame/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CoronaGame/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/CoronaGame/ComputerAI.cpp$(ObjectSuffix): ComputerAI.cpp ../build-$(ConfigurationName)/CoronaGame/ComputerAI.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thomas/Documents/Wumpus/CoronaGame/ComputerAI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ComputerAI.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CoronaGame/ComputerAI.cpp$(DependSuffix): ComputerAI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CoronaGame/ComputerAI.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CoronaGame/ComputerAI.cpp$(DependSuffix) -MM ComputerAI.cpp

../build-$(ConfigurationName)/CoronaGame/ComputerAI.cpp$(PreprocessSuffix): ComputerAI.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CoronaGame/ComputerAI.cpp$(PreprocessSuffix) ComputerAI.cpp

../build-$(ConfigurationName)/CoronaGame/WriteRead.cpp$(ObjectSuffix): WriteRead.cpp ../build-$(ConfigurationName)/CoronaGame/WriteRead.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thomas/Documents/Wumpus/CoronaGame/WriteRead.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/WriteRead.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CoronaGame/WriteRead.cpp$(DependSuffix): WriteRead.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CoronaGame/WriteRead.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CoronaGame/WriteRead.cpp$(DependSuffix) -MM WriteRead.cpp

../build-$(ConfigurationName)/CoronaGame/WriteRead.cpp$(PreprocessSuffix): WriteRead.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CoronaGame/WriteRead.cpp$(PreprocessSuffix) WriteRead.cpp

../build-$(ConfigurationName)/CoronaGame/Play.cpp$(ObjectSuffix): Play.cpp ../build-$(ConfigurationName)/CoronaGame/Play.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thomas/Documents/Wumpus/CoronaGame/Play.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Play.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CoronaGame/Play.cpp$(DependSuffix): Play.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CoronaGame/Play.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CoronaGame/Play.cpp$(DependSuffix) -MM Play.cpp

../build-$(ConfigurationName)/CoronaGame/Play.cpp$(PreprocessSuffix): Play.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CoronaGame/Play.cpp$(PreprocessSuffix) Play.cpp

../build-$(ConfigurationName)/CoronaGame/Instructions.cpp$(ObjectSuffix): Instructions.cpp ../build-$(ConfigurationName)/CoronaGame/Instructions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thomas/Documents/Wumpus/CoronaGame/Instructions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Instructions.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CoronaGame/Instructions.cpp$(DependSuffix): Instructions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CoronaGame/Instructions.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CoronaGame/Instructions.cpp$(DependSuffix) -MM Instructions.cpp

../build-$(ConfigurationName)/CoronaGame/Instructions.cpp$(PreprocessSuffix): Instructions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CoronaGame/Instructions.cpp$(PreprocessSuffix) Instructions.cpp

../build-$(ConfigurationName)/CoronaGame/GenerateMap.cpp$(ObjectSuffix): GenerateMap.cpp ../build-$(ConfigurationName)/CoronaGame/GenerateMap.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thomas/Documents/Wumpus/CoronaGame/GenerateMap.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GenerateMap.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/CoronaGame/GenerateMap.cpp$(DependSuffix): GenerateMap.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/CoronaGame/GenerateMap.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/CoronaGame/GenerateMap.cpp$(DependSuffix) -MM GenerateMap.cpp

../build-$(ConfigurationName)/CoronaGame/GenerateMap.cpp$(PreprocessSuffix): GenerateMap.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/CoronaGame/GenerateMap.cpp$(PreprocessSuffix) GenerateMap.cpp


-include ../build-$(ConfigurationName)/CoronaGame//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


