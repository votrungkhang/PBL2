#include "BuuKien.h"

BuuKien::BuuKien(const std::string& maBuuKien)
    : maBuuKien(maBuuKien) {}

const std::string& BuuKien::getMaBuuKien() const {
    return maBuuKien;
}

void BuuKien::setMaBuuKien(const std::string& maMoi) {
    maBuuKien = maMoi;
}
