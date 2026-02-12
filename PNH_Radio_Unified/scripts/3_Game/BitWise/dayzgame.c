/*
 * PNH_Radio - Unified DayZGame Module
 * Unifica BitWise Framework e RadioNotifications
 */

#ifdef BITWISEDEBUG
void BITWISE_SERVERTEST1(PlayerIdentity sender, ParamsReadContext ctx) {
	Print("BITWISE_SERVERTEST1");
}
#endif

modded class DayZGame {
	
	void DayZGame() {
		// --- Inicialização do Rádio ---
		RadioNotificationSettings.Init();
		
		#ifdef SERVER
			RadioNotificationSettings.GetSettings().Load();
			RadioNotificationSettings.GetSettings().InitOneTimePad();
			
			// Registra os canais de comunicação no BitWise
			GetBitWiseManager().RegisterEndpoint("RadioNotifications", "CONFIGURATION");
			GetBitWiseManager().RegisterEndpoint("RadioNotifications", "RADIONOTIFICATION");
			GetBitWiseManager().RegisterEndpoint("RadioNotifications", "RADIONOTIFICATIONALARM");
			
			// Cria o Manager Global do Servidor
			g_RadioNotificationManager = new RadioNotificationManager();
		#else
			// Lógica de Cliente
			KeysToUIElements.Init(); 
			RadioNotificationSettings.GetSettings().DefaultSettings();
			g_RadioNotificationClientHandler = new RadioNotificationClientHandler();
		#endif

		// --- Inicialização de Debug do BitWise (Opcional) ---
		#ifdef BITWISEDEBUG
			#ifdef SERVER
				GetBitWiseManager().RegisterEndpoint("BITWISE", "servertest1");
			#endif
		#endif
	}

	override void DeferredInit() {
		// Detecta os sons configurados no config.cpp
		RadioNotificationSettings.GetSettings().DetectSoundSets();
		super.DeferredInit();
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		// Redireciona mensagens do BitWise para o Manager correto
		if (rpc_type == RPC_ANTIHAX_BITWISE)
		{
			GetBitWiseManager()._OnRPC(sender, target, ctx);
		}
		else
		{
			super.OnRPC(sender, target, rpc_type, ctx);
		}
	}

	void ~DayZGame() {
		#ifdef SERVER
			g_RadioNotificationManager = null;
		#else
			g_RadioNotificationClientHandler = null;
		#endif
	}
};