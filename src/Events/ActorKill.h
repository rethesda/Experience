#pragma once

#include "Experience.h"

class ActorKillEventHandler : public ExperienceManager::Source, 
	public RE::BSTEventSink<RE::ActorKill::Event>
{
public:
	using ActorKillEventSource = RE::BSTEventSource<RE::ActorKill::Event>;

	ActorKillEventHandler(ExperienceManager* manager);
	~ActorKillEventHandler();

	RE::BSEventNotifyControl ProcessEvent(const RE::ActorKill::Event* event, ActorKillEventSource* source) override;

	static RE::TESNPC* GetTemplateBase(RE::Actor* actor);

	float GetBaseReward(RE::Actor* victim);
	static float GetLevelMult(const RE::Actor* victim, const RE::Actor* killer);
	static float GetGroupMult(const RE::PlayerCharacter* player);

	static float GetPlayerDamagePercent(RE::Actor* actor);

	static bool IsValidKill(RE::Actor* victim, RE::Actor* killer);

private:

	std::unordered_map<RE::TESForm*, int> races;
	std::unordered_map<RE::TESForm*, int> npcs;
};
