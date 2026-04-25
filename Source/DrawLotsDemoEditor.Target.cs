/**
@author		Shun Moriya
@copyright	2024- Shun Moriya
All Rights Reserved.

https://www.youtube.com/channel/UCkLXe57GpUyaOoj2ycREU1Q
*/

using UnrealBuildTool;
using System.Collections.Generic;

public class DrawLotsDemoEditorTarget : TargetRules
{
	public DrawLotsDemoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;

		ExtraModuleNames.AddRange( new string[] { "DrawLotsDemo" } );
	}
}
