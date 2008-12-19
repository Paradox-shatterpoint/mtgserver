/*
 *	server/zone/objects/scene/SceneObject.h generated by engine3 IDL compiler 0.55
 */

#ifndef SCENEOBJECT_H_
#define SCENEOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/service/proto/BaseMessage.h"

#include "engine/service/proto/StandaloneBaseMessage.h"

#include "engine/util/QuadTreeEntry.h"

#include "../../ZoneProcessServerImplementation.h"

class ObjectMenuResponse;

class Zone;

class ZoneClientSession;

class Player;

class Weapon;

class CreatureObject;

class BuildingObject;

class AttackTargetSkill;

#include "engine/core/ManagedObject.h"

class SceneObject : public ManagedObject {
public:
	bool destroy();

	void redeploy();

	void scheduleUndeploy();

	void removeUndeploymentEvent();

	void sendTo(Player* player, bool doClose = true);

	void sendDestroyTo(Player* player);

	void sendRadialResponseTo(Player* player, ObjectMenuResponse* omr);

	void create(ZoneClientSession* client);

	void destroy(ZoneClientSession* client);

	void sendConversationStartTo(SceneObject* obj);

	void selectConversationOption(int option, SceneObject* obj);

	void close(ZoneClientSession* client);

	bool isInRange(SceneObject* obj, float range);

	bool isInRange(float x, float y, float range);

	int inRangeObjectCount();

	QuadTreeEntry* getInRangeObject(int idx);

	void addInRangeObject(QuadTreeEntry* obj, bool notifyUpdate = true);

	void removeInRangeObject(QuadTreeEntry* obj);

	bool isInQuadTree();

	QuadTreeEntry* getQuadTreeEntry();

	int compareTo(SceneObject* obj);

	BaseMessage* link(SceneObject* obj);

	void link(ZoneClientSession* client, SceneObject* obj);

	void randomizePosition(float radius);

	int useObject(Player* player);

	void initializePosition(float x, float z, float y);

	void setPosition(float x, float z, float y);

	void setPositionX(float x);

	void setPositionZ(float z);

	void setPositionY(float y);

	void setDirection(float x, float z, float y, float w);

	void generateAttributes(Player* player);

	void info(const String& message, bool forcedLog = false);

	void error(const String& message);

	void setZoneProcessServer(ZoneProcessServerImplementation* processor);

	void setObjectID(unsigned long long oid);

	void setObjectCRC(unsigned int crc);

	void setObjectType(int tp);

	void setMovementCounter(unsigned int cntr);

	void setZoneIndex(int id);

	void setAssociatedArea(unsigned long long uid);

	void setParent(SceneObject* par, unsigned int linktype = 04);

	void setZone(Zone* zne);

	void clearUndeploymentEvent();

	void insertToZone(Zone* zone);

	void insertToBuilding(BuildingObject* building);

	void removeFromZone(bool doLock = true);

	void removeFromBuilding(BuildingObject* building);

	void broadcastMessage(BaseMessage* msg, int range = 128, bool doLock = true, bool sendSelf = true);

	void broadcastMessage(StandaloneBaseMessage* msg, int range = 128, bool doLock = true);

	bool isUndeploymentScheduled();

	int getObjectType();

	unsigned long long getObjectID();

	unsigned int getObjectCRC();

	unsigned int getMovementCounter();

	float getPositionX();

	float getPositionZ();

	float getPositionY();

	int getDirectionAngle();

	float getDirectionX();

	float getDirectionZ();

	float getDirectionY();

	float getDirectionW();

	String& getLoggingName();

	unsigned long long getAssociatedArea();

	bool isPlayer();

	bool isNonPlayerCreature();

	bool isBuilding();

	bool isCell();

	bool isTangible();

	bool isIntangible();

	bool isStatic();

	bool isShip();

	bool isAttackableObject();

	bool isMission();

	bool isPlayerObject();

	bool isWaypoint();

	bool isManufactureSchematic();

	Zone* getZone();

	int getZoneID();

	SceneObject* getParent();

	unsigned long long getParentID();

	bool isMoving();

	void switchMovingState();

	bool doKeepObject();

	ZoneProcessServerImplementation* getZoneProcessServer();

	void setCombatState();

	void clearCombatState(bool removedefenders = true);

	void setDefender(SceneObject* defender);

	void addDefender(SceneObject* defender);

	void removeDefenders();

	void removeDefender(SceneObject* defender);

	bool hasDefender(SceneObject* defender);

	SceneObject* getDefender(int idx);

	unsigned int getDefenderListSize();

	bool isPeaced();

	bool isAttackableBy(CreatureObject* creature);

	bool isInANoBuildArea();

	void addDamageDone(CreatureObject* creature, int damage, String& skillname);

	void dropDamageDone(CreatureObject* creature);

	int getTotalDamage();

	void disseminateXp(int levels);

protected:
	SceneObject(DummyConstructorParameter* param);

	virtual ~SceneObject();

	bool _destroy();

	String _return_getLoggingName;

	friend class SceneObjectHelper;
};

class SceneObjectImplementation;

class SceneObjectAdapter : public ManagedObjectAdapter {
public:
	SceneObjectAdapter(SceneObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	bool destroy();

	void redeploy();

	void scheduleUndeploy();

	void removeUndeploymentEvent();

	void sendTo(Player* player, bool doClose);

	void sendDestroyTo(Player* player);

	void sendRadialResponseTo(Player* player, ObjectMenuResponse* omr);

	void create(ZoneClientSession* client);

	void destroy(ZoneClientSession* client);

	void sendConversationStartTo(SceneObject* obj);

	void selectConversationOption(int option, SceneObject* obj);

	void close(ZoneClientSession* client);

	bool isInRange(SceneObject* obj, float range);

	bool isInRange(float x, float y, float range);

	int inRangeObjectCount();

	QuadTreeEntry* getInRangeObject(int idx);

	void addInRangeObject(QuadTreeEntry* obj, bool notifyUpdate);

	void removeInRangeObject(QuadTreeEntry* obj);

	bool isInQuadTree();

	QuadTreeEntry* getQuadTreeEntry();

	int compareTo(SceneObject* obj);

	BaseMessage* link(SceneObject* obj);

	void link(ZoneClientSession* client, SceneObject* obj);

	void randomizePosition(float radius);

	int useObject(Player* player);

	void initializePosition(float x, float z, float y);

	void setPosition(float x, float z, float y);

	void setPositionX(float x);

	void setPositionZ(float z);

	void setPositionY(float y);

	void setDirection(float x, float z, float y, float w);

	void generateAttributes(Player* player);

	void info(const String& message, bool forcedLog);

	void error(const String& message);

	void setObjectID(unsigned long long oid);

	void setObjectCRC(unsigned int crc);

	void setObjectType(int tp);

	void setMovementCounter(unsigned int cntr);

	void setZoneIndex(int id);

	void setAssociatedArea(unsigned long long uid);

	void setParent(SceneObject* par, unsigned int linktype);

	void setZone(Zone* zne);

	void clearUndeploymentEvent();

	void insertToZone(Zone* zone);

	void insertToBuilding(BuildingObject* building);

	void removeFromZone(bool doLock);

	void removeFromBuilding(BuildingObject* building);

	void broadcastMessage(BaseMessage* msg, int range, bool doLock, bool sendSelf);

	void broadcastMessage(StandaloneBaseMessage* msg, int range, bool doLock);

	bool isUndeploymentScheduled();

	int getObjectType();

	unsigned long long getObjectID();

	unsigned int getObjectCRC();

	unsigned int getMovementCounter();

	float getPositionX();

	float getPositionZ();

	float getPositionY();

	int getDirectionAngle();

	float getDirectionX();

	float getDirectionZ();

	float getDirectionY();

	float getDirectionW();

	String& getLoggingName();

	unsigned long long getAssociatedArea();

	bool isPlayer();

	bool isNonPlayerCreature();

	bool isBuilding();

	bool isCell();

	bool isTangible();

	bool isIntangible();

	bool isStatic();

	bool isShip();

	bool isAttackableObject();

	bool isMission();

	bool isPlayerObject();

	bool isWaypoint();

	bool isManufactureSchematic();

	Zone* getZone();

	int getZoneID();

	SceneObject* getParent();

	unsigned long long getParentID();

	bool isMoving();

	void switchMovingState();

	bool doKeepObject();

	void setCombatState();

	void clearCombatState(bool removedefenders);

	void setDefender(SceneObject* defender);

	void addDefender(SceneObject* defender);

	void removeDefenders();

	void removeDefender(SceneObject* defender);

	bool hasDefender(SceneObject* defender);

	SceneObject* getDefender(int idx);

	unsigned int getDefenderListSize();

	bool isPeaced();

	bool isAttackableBy(CreatureObject* creature);

	bool isInANoBuildArea();

	void addDamageDone(CreatureObject* creature, int damage, String& skillname);

	void dropDamageDone(CreatureObject* creature);

	int getTotalDamage();

	void disseminateXp(int levels);

protected:
	String _param0_info__String_bool_;
	String _param0_error__String_;
	String _param2_addDamageDone__CreatureObject_int_String_;
};

class SceneObjectHelper : public DistributedObjectClassHelper, public Singleton<SceneObjectHelper> {
	static SceneObjectHelper* staticInitializer;

public:
	SceneObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<SceneObjectHelper>;
};

#include "engine/core/ManagedObjectImplementation.h"

class SceneObjectServant : public ManagedObjectImplementation {
public:
	SceneObject* _this;

public:
	SceneObjectServant();
	virtual ~SceneObjectServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*SCENEOBJECT_H_*/
