// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameJamConversion : ModuleRules
{
	public GameJamConversion(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
