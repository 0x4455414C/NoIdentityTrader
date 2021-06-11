class CfgPatches
{
	class NoIdentityAI
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class NoIdentityAI
	{
		dir="NoIdentityAI";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="NoIdentityAI";
		credits="DUAL";
		author="DUAL";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"NoIdentityAI\4_World"
				};
			};
		};
	};
};
