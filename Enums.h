#define RWI_NAME_TAG "RayWorldIntersection(Game)"

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

enum EBonesID
{
	BONE_BIP01 = 0,
	BONE_SPINE,
	BONE_SPINE2,
	BONE_SPINE3,
	BONE_HEAD,
	BONE_EYE_R,
	BONE_EYE_L,
	BONE_WEAPON,
	BONE_WEAPON2,
	BONE_FOOT_R,
	BONE_FOOT_L,
	BONE_ARM_R,
	BONE_ARM_L,
	BONE_CALF_R,
	BONE_CALF_L,
	BONE_CAMERA,
	BONE_AUTOAIMTARGET,
	BONE_AUTOAIMTARGET_ALIEN,
	BONE_ALIEN_HEAD,
	BONE_ID_NUM
};


enum EBone
{
	Bone_Pelvis = 1,
	Bone_Locomotion,
	Bone_Spine,
	Bone_L_Thigh,
	Bone_R_Thigh,
	Bone_Groin_Back,
	Bone_Groin_Front,
	Bone_Spine1,
	Bone_Spine2,
	Bone_Spine3,
	Bone_Wep_Law,
	Bone_Neck,
	Bone_Head,
	Bone_L_Clavicle,
	Bone_R_Clavicle,
	Bone_L_Eye,
	Bone_R_Eye,
	Bone_Camera,
	Bone_L_Eye_01,
	Bone_R_Eye_01,
	Bone_HNeck,
	Bone_Camera_01,
	Bone_HNeck_End,
	Bone_L_UpperArm,
	Bone_L_Forearm,
	Bone_L_Hand,
	Bone_L_ForeTwist,
	Bone_L_Finger0,
	Bone_L_Finger1,
	Bone_L_Finger2,
	Bone_L_Finger3,
	Bone_L_Finger4,
	Bone_Wep_Alt,
	Bone_L_Hand_Push,
	Bone_L_Finger01,
	Bone_L_Finger02,
	Bone_L_Finger11,
	Bone_L_Finger12,
	Bone_L_Finger21,
	Bone_L_Finger22,
	Bone_L_Finger31,
	Bone_L_Finger32,
	Bone_L_Finger41,
	Bone_L_Finger42,
	Bone_L_ForeTwist_1,
	Bone_L_ForeTwist_2,
	Bone_R_UpperArm,
	Bone_R_Forearm,
	Bone_R_Hand,
	Bone_R_ForeTwist,
	Bone_R_Finger0,
	Bone_R_Finger1,
	Bone_R_Finger2,
	Bone_R_Finger3,
	Bone_R_Finger4,
	Bone_WepBone,
	Bone_R_Hand_Push,
	Bone_R_Finger01,
	Bone_R_Finger02,
	Bone_R_Finger11,
	Bone_R_Finger12,
	Bone_R_Finger21,
	Bone_R_Finger22,
	Bone_R_Finger31,
	Bone_R_Finger32,
	Bone_R_Finger41,
	Bone_R_Finger42,
	Bone_R_ForeTwist_1,
	Bone_R_ForeTwist_2,
	Bone_L_Calf,
	Bone_L_Foot,
	Bone_L_Toe0,
	Bone_L_Heel,
	Bone_L_Heel01,
	Bone_L_Toe0Nub,
	Bone_L_Toe0Nub01,
	Bone_R_Calf,
	Bone_R_Foot,
	Bone_R_Toe0,
	Bone_R_Heel,
	Bone_R_Heel01,
	Bone_R_Toe0Nub,
	Bone_R_Toe0Nub01,
	Bone_Groin_Back_End,
	Bone_Groin_Front_End,
	Bone_Locator_Collider
};

enum phentity_flags {
	// PE_PARTICLE-specific flags
	particle_single_contact = 0x01, // full stop after first contact
	particle_constant_orientation = 0x02, // forces constant orientation
	particle_no_roll = 0x04, // 'sliding' mode; entity's 'normal' vector axis will be alinged with the ground normal
	particle_no_path_alignment = 0x08, // unless set, entity's y axis will be aligned along the movement trajectory
	particle_no_spin = 0x10, // disables spinning while flying
	particle_no_self_collisions = 0x100, // disables collisions with other particles
	particle_no_impulse = 0x200, // particle will not add hit impulse (expecting that some other system will) 

	// PE_LIVING-specific flags
	lef_push_objects = 0x01, lef_push_players = 0x02,	// push objects and players during contacts
	lef_snap_velocities = 0x04,	// quantizes velocities after each step (was ised in MP for precise deterministic sync)
	lef_loosen_stuck_checks = 0x08, // don't do additional intersection checks after each step (recommended for NPCs to improve performance)
	lef_report_sliding_contacts = 0x10,	// unless set, 'grazing' contacts are not reported 

	// PE_ROPE-specific flags
	rope_findiff_attached_vel = 0x01, // approximate velocity of the parent object as v = (pos1-pos0)/time_interval
	rope_no_solver = 0x02, // no velocity solver; will rely on stiffness (if set) and positional length enforcement
	rope_ignore_attachments = 0x4, // no collisions with objects the rope is attached to
	rope_target_vtx_rel0 = 0x08, rope_target_vtx_rel1 = 0x10, // whether target vertices are set in the parent entity's frame
	rope_subdivide_segs = 0x100, // turns on 'dynamic subdivision' mode (only in this mode contacts in a strained state are handled correctly)
	rope_no_tears = 0x200, // rope will not tear when it reaches its force limit, but stretch
	rope_collides = 0x200000, // rope will collide with objects other than the terrain
	rope_collides_with_terrain = 0x400000, // rope will collide with the terrain
	rope_collides_with_attachment = 0x80, // rope will collide with the objects it's attached to even if the other collision flags are not set
	rope_no_stiffness_when_colliding = 0x10000000, // rope will use stiffness 0 if it has contacts

	// PE_SOFT-specific flags
	se_skip_longest_edges = 0x01,	// the longest edge in each triangle with not participate in the solver

	// PE_RIGID-specific flags (note that PE_ARTICULATED and PE_WHEELEDVEHICLE are derived from it)
	ref_use_simple_solver = 0x01,	// use penalty-based solver (obsolete)
	ref_no_splashes = 0x04, // will not generate EventPhysCollisions when contacting water
	ref_checksum_received = 0x04, ref_checksum_outofsync = 0x08, // obsolete

	// PE_ARTICULATED-specific flags
	aef_recorded_physics = 0x02, // specifies a an entity that contains pre-baked physics simulation

	// PE_WHEELEDVEHICLE-specific flags
	wwef_fake_inner_wheels = 0x08, // exclude wheels between the first and the last one from the solver
	// (only wheels with non-0 suspension are considered)

// general flags
pef_parts_traceable = 0x10,	// each entity part will be registered separately in the entity grid
pef_disabled = 0x20, // entity will not be simulated
pef_never_break = 0x40, // entity will not break or deform other objects
pef_deforming = 0x80, // entity undergoes a dynamic breaking/deforming
pef_pushable_by_players = 0x200, // entity can be pushed by playerd	
pef_traceable = 0x400, particle_traceable = 0x400, rope_traceable = 0x400, // entity is registered in the entity grid
pef_update = 0x800, // only entities with this flag are updated if ent_flagged_only is used in TimeStep()
pef_monitor_state_changes = 0x1000, // generate immediate events for simulation class changed (typically rigid bodies falling asleep)
pef_monitor_collisions = 0x2000, // generate immediate events for collisions
pef_monitor_env_changes = 0x4000,	// generate immediate events when something breaks nearby
pef_never_affect_triggers = 0x8000,	// don't generate events when moving through triggers
pef_invisible = 0x10000, // will apply certain optimizations for invisible entities
pef_ignore_ocean = 0x20000, // entity will ignore global water area
pef_fixed_damping = 0x40000,	// entity will force its damping onto the entire group
pef_monitor_poststep = 0x80000, // entity will generate immediate post step events
pef_always_notify_on_deletion = 0x100000,	// when deleted, entity will awake objects around it even if it's not referenced (has refcount 0)
pef_override_impulse_scale = 0x200000, // entity will ignore breakImpulseScale in PhysVars
pef_players_can_break = 0x400000, // playes can break the entiy by bumping into it
pef_cannot_squash_players = 0x10000000,	// entity will never trigger 'squashed' state when colliding with players
pef_ignore_areas = 0x800000, // entity will ignore phys areas (gravity and water)
pef_log_state_changes = 0x1000000, // entity will log simulation class change events
pef_log_collisions = 0x2000000, // entity will log collision events
pef_log_env_changes = 0x4000000, // entity will log EventPhysEnvChange when something breaks nearby
pef_log_poststep = 0x8000000 // entity will log EventPhysPostStep events
};

enum entity_query_flags{ // see GetEntitiesInBox and RayWorldIntersection
	ent_static = 1, ent_sleeping_rigid = 2, ent_rigid = 4, ent_living = 8, ent_independent = 16, ent_deleted = 128, ent_terrain = 0x100,
	ent_all = ent_static | ent_sleeping_rigid | ent_rigid | ent_living | ent_independent | ent_terrain,
	ent_flagged_only = pef_update, ent_skip_flagged = pef_update * 2, // "flagged" meas has pef_update set
	ent_areas = 32, ent_triggers = 64,
	ent_ignore_noncolliding = 0x10000,
	ent_sort_by_mass = 0x20000, // sort by mass in ascending order
	ent_allocate_list = 0x40000, // if not set, the function will return an internal pointer
	ent_water = 0x200, // can only be used in RayWorldIntersection
	ent_no_ondemand_activation = 0x80000, // can only be used in RayWorldIntersection
	ent_delayed_deformations = 0x80000 // queues procedural breakage requests; can only be used in SimulateExplosion
};

enum draw_helper_flags { pe_helper_collisions = 1, pe_helper_geometry = 2, pe_helper_bbox = 4, pe_helper_lattice = 8 };
enum surface_flags { sf_pierceable_mask = 0x0F, sf_max_pierceable = 0x0F, sf_important = 0x200, sf_manually_breakable = 0x400, sf_matbreakable_bit = 16 };

enum rwi_flags { // see RayWorldIntersection
	rwi_ignore_terrain_holes = 0x20, rwi_ignore_noncolliding = 0x40, rwi_ignore_back_faces = 0x80, rwi_ignore_solid_back_faces = 0x100,
	rwi_pierceability_mask = 0x0F, rwi_pierceability0 = 0, rwi_stop_at_pierceable = 0x0F,
	rwi_separate_important_hits = sf_important,	// among pierceble hits, materials with sf_important will have priority
	rwi_colltype_bit = 16, // used to manually specify collision geometry types (default is geom_colltype_ray)
	rwi_colltype_any = 0x400, // if several colltype flag are specified, switches between requiring all or any of them in a geometry
	rwi_queue = 0x800, // queues the RWI request, when done it'll generate EventPhysRWIResult
	rwi_force_pierceable_noncoll = 0x1000, // non-colliding geometries will be treated as pierceable regardless of the actual material
	rwi_reuse_last_hit = 0x2000, // use phitLast for "warm" start
	rwi_update_last_hit = 0x4000, // update phitLast with the current hit results
	rwi_any_hit = 0x8000 // returns the first found hit for meshes, not necessarily the closets
};

#define  IS   D3DCOLOR_ARGB(255, 62, 62, 64)
#define  ON   D3DCOLOR_ARGB(255, 14, 151, 189)
#define  EX   D3DCOLOR_ARGB(255, 128, 128, 128)
#define  BUT  D3DCOLOR_ARGB(255, 40, 40, 40)
#define  BUTT     D3DCOLOR_ARGB(255, 50, 50, 50)
#define	 HP_YELLOW		D3DCOLOR_ARGB(255, 255, 255, 000)
#define	 HP_LIME		D3DCOLOR_ARGB(255, 204, 255, 000)
#define	 HP_YELGREEN	D3DCOLOR_ARGB(255, 173, 255, 47)
#define	 HP_DEEPGREEN	D3DCOLOR_ARGB(255, 10, 255, 145)
#define	 HP_LGREEN		D3DCOLOR_ARGB(255, 102, 255, 000)
#define	 HP_GREEN		D3DCOLOR_ARGB(255, 000, 255, 000)
#define DT_SHADOW           0x0040    
#define BLUEMAZAY       D3DCOLOR_ARGB(250, 21,  76,  148)
#define DARKGREY        D3DCOLOR_ARGB(255, 70,68, 81)   
#define  DARK1            D3DCOLOR_ARGB(255, 10, 10, 10)
#define  DARK2            D3DCOLOR_ARGB(255, 15, 15, 15)
#define  DARK3            D3DCOLOR_ARGB(255, 20, 20, 20)
#define  DARK4            D3DCOLOR_ARGB(255, 25, 25, 25)
#define  DARKNEW            D3DCOLOR_ARGB(255, 29, 29, 29)
#define  DARK6            D3DCOLOR_ARGB(255, 35, 35, 35)
#define  DARK8            D3DCOLOR_ARGB(255, 45, 45, 45)
#define  DARK10           D3DCOLOR_ARGB(255, 60, 60, 60)
#define  DARK11           D3DCOLOR_ARGB(255, 65, 65, 65)
#define  DARK15           D3DCOLOR_ARGB(255, 85, 85, 85)
#define  DARK20           D3DCOLOR_ARGB(255, 150, 150, 150)
#define DARKMAZAY2		D3DCOLOR_ARGB(180, 49,   54,  40)
#define DARKMAZAY 		D3DCOLOR_ARGB(180, 24,   24,  20)
#define GREENMAZAY		D3DCOLOR_ARGB(250, 71,  122,  62)
#define DarkRed         D3DCOLOR_ARGB(255,52,0,0)
#define DarkRed2        D3DCOLOR_ARGB(255,72,0,0)
#define DarkYellow		D3DCOLOR_ARGB(255, 210, 197, 0)
#define DARKMAZAY3 		D3DCOLOR_ARGB(255, 24,   24,  20)
#define C_BOX			D3DCOLOR_ARGB(200, 33, 33, 33)
#define ForestGreen     D3DCOLOR_ARGB (255, 34, 139, 34)