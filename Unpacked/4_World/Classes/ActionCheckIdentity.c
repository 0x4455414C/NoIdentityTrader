modded class ActionCheckIdentity {
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        EntityAI targetEntity = EntityAI.Cast(target.GetObject());
        bool isTrader = false;

        if (targetEntity && targetEntity.IsPlayer()) {
            PlayerBase targetPlayer = PlayerBase.Cast(target.GetObject());
            CIConfig config = GetDayZGame().GetCheckIdentityConfig();
            isTrader = targetPlayer.m_Trader_IsTrader;
			
            if (!isTrader){
                m_ActionTypeText = "Check Identity";
                m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
                return true;
            }
        }
        return false;
    }

    override void OnEndServer(ActionData action_data) {
        PlayerBase targetPlayer = PlayerBase.Cast(action_data.m_Target.GetObject());
        PlayerBase player = action_data.m_Player;

        // if (targetPlayer.GetCharacterName() == string.Empty && targetPlayer.IsAI())
        // targetPlayer.SetRandomCharacterName();

        auto data = new Param1 < string > (targetPlayer.GetCharacterName());
        GetGame().RPCSingleParam(player, CIRPC.CHECKCHARACTERNAME, data, true, player.GetIdentity());
    }
}