#include "TrackerHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "TrackerSD.hh"
#include <iomanip>

G4ThreadLocal G4Allocator<TrackerHit>* TrackerHitAllocator=0;

TrackerHit::TrackerHit()
 : G4VHit(),
   fTrackID(-1),
   fEdep(0.),
   fPos(G4ThreeVector()),
   fP(G4ThreeVector()),
   fn(0),
   fKe(0)
{}

TrackerHit::~TrackerHit() {}

TrackerHit::TrackerHit(const TrackerHit& hit)
  : G4VHit()
{
  fTrackID   = hit.fTrackID;
  fEdep      = hit.fEdep;
  fPos       = hit.fPos;
  fP = hit.fP;
  fn = hit.fn;
  fKe = hit.fKe;
}

const TrackerHit& TrackerHit::operator=(const TrackerHit& hit)
{
  fTrackID   = hit.fTrackID;
  fEdep      = hit.fEdep;
  fPos       = hit.fPos;
  fP = hit.fP;
  fn = hit.fn;
  fKe = hit.fKe;

  return *this;
}

G4int TrackerHit::operator==(const TrackerHit& hit) const
{
  return ( this == &hit ) ? 1 : 0;
}

