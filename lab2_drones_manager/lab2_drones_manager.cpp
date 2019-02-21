#include "lab2_drones_manager.h"

// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
	first = NULL;
	last = NULL;
	size = 0;
}

DronesManager::~DronesManager() {
	DroneRecord* curr=first;
	while (curr) {
	DroneRecord* prev = curr;
		curr = curr->next;
		delete prev;
	}
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	bool is_equal=true;
	is_equal = is_equal && lhs.droneID == rhs.droneID;
	is_equal = is_equal && lhs.range == rhs.range;
	is_equal = is_equal && lhs.yearBought== rhs.yearBought;
	is_equal = is_equal && lhs.droneType == rhs.droneType;
	is_equal = is_equal && lhs.manufacturer == rhs.manufacturer;
	is_equal = is_equal && lhs.description == rhs.description;
	is_equal = is_equal && lhs.batteryType== rhs.batteryType;
	return is_equal;
}

unsigned int DronesManager::get_size() const {
	DroneRecord*curr = first;
	int counter = 0;
	while (curr) {
		curr = curr->next;
		counter++;
	}
	return counter;
}

bool DronesManager::empty() const {
	if (size == 0)
		return true;
	return false;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	DroneRecord*curr = first;

	if (size == 0);
		return *curr;

	if (size < index)
		return *last;

	for (int counter = 0; counter < index; counter++) {
		curr = curr->next;
	}

	DroneRecord curr_record = *curr;
	return curr_record;
}

unsigned int DronesManager::search(DroneRecord value) const {
	DroneRecord* curr = first;
	int counter = 0;
	if (size == 0);
		return 0;

	while (curr) {
		curr = curr->next;
		DroneRecord curr_Record = *curr;
		if (curr_Record == value);
			return counter;
		counter++;
	}
	return counter;
}

void DronesManager::print() const {

}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	DroneRecord* curr = first;
	DroneRecord* previous;
	DroneRecord* val_pointer = &value;

	if (size < index)
		return false;

	for (int counter = 0; counter < index; counter++) {
		previous = curr;
		curr = curr->next;
	}

	previous->next = val_pointer;
	val_pointer->prev = previous;
	val_pointer->next = curr;
	curr->prev = val_pointer;

	return true;
}

bool DronesManager::insert_front(DroneRecord value) {
	DroneRecord* curr = first;
	*first = value;
	first->next = curr;
	curr->prev = first;
	first->prev = NULL;
	return true;
}

bool DronesManager::insert_back(DroneRecord value) {
	DroneRecord* val_pointer = &value;
	last->next = val_pointer;
	val_pointer->prev = last;
	return true;	
}

bool DronesManager::remove(unsigned int index) {
	DroneRecord* curr = first;
	DroneRecord* previous;
	for (int i = 0;i < index; i++) {
		previous = curr;
		curr = curr->next;
	}

	DroneRecord* curr_next=curr->next;
	previous = curr_next;
	curr_next->prev = previous;
	delete curr;
	return true;
}

bool DronesManager::remove_front() {
	DroneRecord* old_first = first;
	first = first->next;
	first->prev = NULL;
	old_first->next = NULL;
	delete old_first;
	return true;
}

bool DronesManager::remove_back() {
	DroneRecord *old_last = last;
	last = last->prev;
	last->next = NULL;
	delete old_last;
	return false;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	if (index < size)
		return false;

	DroneRecord* curr = first;
	DroneRecord* previous;
	DroneRecord* replacement = &value;
	for (int i = 0; i < index; i++) {
		previous = curr;
		curr = curr->next;
	}
	previous->next = replacement;
	replacement->next = curr->next;
	curr->next->prev = replacement;
	replacement->prev = previous;
	delete curr;
	return true;
}

bool DronesManager::reverse_list() {
	DroneRecord *curr = last;
	DroneRecord *previous = last->prev;
	DroneRecord *temp_one = last;
	DroneRecord* temp_two = last->prev;
	DroneRecord* last_temp = last;

	curr->prev = NULL;
	while (previous) {
		curr->next = previous;
		previous->prev=curr;
		curr = temp_one->prev;
		previous = temp_two->prev;
	}
	curr->next = NULL;
	last = first;
	first = last_temp;
	  
	return false;
}

