#pragma once

#include "Experience.h"

class QuestStatusEventHandler : public ExperienceManager::Source, 
	public RE::BSTEventSink<RE::QuestStatus::Event>
{
public:
	using QuestStatusEventSource = RE::BSTEventSource<RE::QuestStatus::Event>;

	QuestStatusEventHandler(ExperienceManager* manager);
	~QuestStatusEventHandler() override;

	RE::BSEventNotifyControl ProcessEvent(const RE::QuestStatus::Event* event, QuestStatusEventSource* source) override;

private:
	using QuestType = RE::QUEST_DATA::Type;

	bool IsValidCompletion(RE::TESQuest* quest);

	uint8_t GetNumObjectivesCompleted(RE::TESQuest* quest);
	int GetReward(QuestType type);
};
