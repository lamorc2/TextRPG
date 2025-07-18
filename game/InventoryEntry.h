#ifndef INVENTORYENTRY_H
#define INVENTORYENTRY_H


struct InventoryEntry {
    std::string itemID;
    int quantity;

    InventoryEntry(const std::string i, int q){
    	itemID = i;
    	quantity = q;
    }
        

    void to_json(json& j, const InventoryEntry& entry) {
    j = json{
        {"itemID", entry.itemID},
        {"quantity", entry.quantity}
    };
}

};


#endif