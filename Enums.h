enum EEntityProxy
{
	ENTITY_PROXY_RENDER,
	ENTITY_PROXY_PHYSICS,
	ENTITY_PROXY_SCRIPT,
	ENTITY_PROXY_SOUND,
	ENTITY_PROXY_AI,
	ENTITY_PROXY_AREA,
	ENTITY_PROXY_BOIDS,
	ENTITY_PROXY_BOID_OBJECT,
	ENTITY_PROXY_CAMERA,
	ENTITY_PROXY_FLOWGRAPH,
	ENTITY_PROXY_SUBSTITUTION,
	ENTITY_PROXY_TRIGGER,
	ENTITY_PROXY_ROPE,

	ENTITY_PROXY_USER,

	// Always the last entry of the enum.
	ENTITY_PROXY_LAST
};

#define BIT(x) (1<<(x))

enum EEntityFlags
{
	//////////////////////////////////////////////////////////////////////////
	// Persistent flags (can be set from the editor).
	//////////////////////////////////////////////////////////////////////////

	ENTITY_FLAG_CASTSHADOW = BIT(1),
	ENTITY_FLAG_UNREMOVABLE = BIT(2),   // This entity cannot be removed using IEntitySystem::RemoveEntity until this flag is cleared.
	ENTITY_FLAG_GOOD_OCCLUDER = BIT(3),
	ENTITY_FLAG_NO_DECALNODE_DECALS = BIT(4),

	//////////////////////////////////////////////////////////////////////////
	ENTITY_FLAG_WRITE_ONLY = BIT(5),
	ENTITY_FLAG_NOT_REGISTER_IN_SECTORS = BIT(6),
	ENTITY_FLAG_CALC_PHYSICS = BIT(7),
	ENTITY_FLAG_CLIENT_ONLY = BIT(8),
	ENTITY_FLAG_SERVER_ONLY = BIT(9),
	ENTITY_FLAG_CUSTOM_VIEWDIST_RATIO = BIT(10),   // This entity have special custom view distance ratio (AI/Vehicles must have it).
	ENTITY_FLAG_CALCBBOX_USEALL = BIT(11),		// use character and objects in BBOx calculations.
	ENTITY_FLAG_VOLUME_SOUND = BIT(12),		// Entity is a volume sound (will get moved around by the sound proxy).
	ENTITY_FLAG_HAS_AI = BIT(13),		// Entity has an AI object.
	ENTITY_FLAG_TRIGGER_AREAS = BIT(14),   // This entity will trigger areas when it enters them.
	ENTITY_FLAG_NO_SAVE = BIT(15),   // This entity will not be saved.
	ENTITY_FLAG_NET_PRESENT = BIT(16),   // This entity Must be present on network.
	ENTITY_FLAG_CLIENTSIDE_STATE = BIT(17),   // Prevents error when state changes on the client and does not sync state changes to the client.
	ENTITY_FLAG_SEND_RENDER_EVENT = BIT(18),   // When set entity will send ENTITY_EVENT_RENDER every time its rendered.
	ENTITY_FLAG_NO_PROXIMITY = BIT(19),   // Entity will not be registered in the partition grid and can not be found by proximity queries.
	ENTITY_FLAG_ON_RADAR = BIT(20),   // Entity will be relevant for radar.
	ENTITY_FLAG_UPDATE_HIDDEN = BIT(21),   // Entity will be update even when hidden.  
	ENTITY_FLAG_NEVER_NETWORK_STATIC = BIT(22),		// Entity should never be considered a static entity by the network system.
	ENTITY_FLAG_IGNORE_PHYSICS_UPDATE = BIT(23),		// Used by Editor only, (don't set).
	ENTITY_FLAG_SPAWNED = BIT(24),		// Entity was spawned dynamically without a class.
	ENTITY_FLAG_SLOTS_CHANGED = BIT(25),		// Entity's slots were changed dynamically.
	ENTITY_FLAG_MODIFIED_BY_PHYSICS = BIT(26),		// Entity was procedurally modified by physics.
	ENTITY_FLAG_OUTDOORONLY = BIT(27),		// Same as Brush->Outdoor only.
	ENTITY_FLAG_SEND_NOT_SEEN_TIMEOUT = BIT(28),		// Entity will be sent ENTITY_EVENT_NOT_SEEN_TIMEOUT if it is not rendered for 30 seconds.
	ENTITY_FLAG_RECVWIND = BIT(29),		// Receives wind.
	ENTITY_FLAG_LOCAL_PLAYER = BIT(30),
	ENTITY_FLAG_AI_HIDEABLE = BIT(31),  // AI can use the object to calculate automatic hide points.

};