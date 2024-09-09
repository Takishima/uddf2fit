// Copyright (c) 2005-2023 Code Synthesis.
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis gives permission
// to link this program with the Xerces-C++ library (or with modified
// versions of Xerces-C++ that use the same license as Xerces-C++), and
// distribute linked combinations including the two. You must obey the GNU
// General Public License version 2 in all respects for all of the code
// used other than Xerces-C++. If you modify this copy of the program, you
// may extend this exception to your version of the program, but you are
// not obligated to do so. If you do not wish to do so, delete this
// exception statement from your version.
//
// Furthermore, Code Synthesis makes a special exception for the Free/Libre
// and Open Source Software (FLOSS) which is described in the accompanying
// FLOSSE file.
//

#ifndef EQUIPMENT_TYPE_HXX
#define EQUIPMENT_TYPE_HXX

#include "equipmentType-fwd.hxx"

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (LIBXSD_VERSION != 400002000000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include <memory>    // ::std::unique_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search
#include <utility>   // std::move

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

#include "equipmentPieceType-fwd.hxx"

#include "cameraType-fwd.hxx"

#include "equipmentconfigurationType-fwd.hxx"

#include "rebreatherType-fwd.hxx"

#include "suitType-fwd.hxx"

#include "tankType-fwd.hxx"

#include "videocameraType-fwd.hxx"

namespace streit
{
  class equipmentType: public ::xml_schema::type
  {
    public:
    // boots
    //
    typedef ::streit::equipmentPieceType boots_type;
    typedef ::xsd::cxx::tree::sequence< boots_type > boots_sequence;
    typedef boots_sequence::iterator boots_iterator;
    typedef boots_sequence::const_iterator boots_const_iterator;
    typedef ::xsd::cxx::tree::traits< boots_type, char > boots_traits;

    const boots_sequence&
    boots () const;

    boots_sequence&
    boots ();

    void
    boots (const boots_sequence& s);

    // buoyancycontroldevice
    //
    typedef ::streit::equipmentPieceType buoyancycontroldevice_type;
    typedef ::xsd::cxx::tree::sequence< buoyancycontroldevice_type > buoyancycontroldevice_sequence;
    typedef buoyancycontroldevice_sequence::iterator buoyancycontroldevice_iterator;
    typedef buoyancycontroldevice_sequence::const_iterator buoyancycontroldevice_const_iterator;
    typedef ::xsd::cxx::tree::traits< buoyancycontroldevice_type, char > buoyancycontroldevice_traits;

    const buoyancycontroldevice_sequence&
    buoyancycontroldevice () const;

    buoyancycontroldevice_sequence&
    buoyancycontroldevice ();

    void
    buoyancycontroldevice (const buoyancycontroldevice_sequence& s);

    // camera
    //
    typedef ::streit::cameraType camera_type;
    typedef ::xsd::cxx::tree::sequence< camera_type > camera_sequence;
    typedef camera_sequence::iterator camera_iterator;
    typedef camera_sequence::const_iterator camera_const_iterator;
    typedef ::xsd::cxx::tree::traits< camera_type, char > camera_traits;

    const camera_sequence&
    camera () const;

    camera_sequence&
    camera ();

    void
    camera (const camera_sequence& s);

    // compass
    //
    typedef ::streit::equipmentPieceType compass_type;
    typedef ::xsd::cxx::tree::sequence< compass_type > compass_sequence;
    typedef compass_sequence::iterator compass_iterator;
    typedef compass_sequence::const_iterator compass_const_iterator;
    typedef ::xsd::cxx::tree::traits< compass_type, char > compass_traits;

    const compass_sequence&
    compass () const;

    compass_sequence&
    compass ();

    void
    compass (const compass_sequence& s);

    // compressor
    //
    typedef ::streit::equipmentPieceType compressor_type;
    typedef ::xsd::cxx::tree::sequence< compressor_type > compressor_sequence;
    typedef compressor_sequence::iterator compressor_iterator;
    typedef compressor_sequence::const_iterator compressor_const_iterator;
    typedef ::xsd::cxx::tree::traits< compressor_type, char > compressor_traits;

    const compressor_sequence&
    compressor () const;

    compressor_sequence&
    compressor ();

    void
    compressor (const compressor_sequence& s);

    // divecomputer
    //
    typedef ::streit::equipmentPieceType divecomputer_type;
    typedef ::xsd::cxx::tree::sequence< divecomputer_type > divecomputer_sequence;
    typedef divecomputer_sequence::iterator divecomputer_iterator;
    typedef divecomputer_sequence::const_iterator divecomputer_const_iterator;
    typedef ::xsd::cxx::tree::traits< divecomputer_type, char > divecomputer_traits;

    const divecomputer_sequence&
    divecomputer () const;

    divecomputer_sequence&
    divecomputer ();

    void
    divecomputer (const divecomputer_sequence& s);

    // equipmentconfiguration
    //
    typedef ::streit::equipmentconfigurationType equipmentconfiguration_type;
    typedef ::xsd::cxx::tree::sequence< equipmentconfiguration_type > equipmentconfiguration_sequence;
    typedef equipmentconfiguration_sequence::iterator equipmentconfiguration_iterator;
    typedef equipmentconfiguration_sequence::const_iterator equipmentconfiguration_const_iterator;
    typedef ::xsd::cxx::tree::traits< equipmentconfiguration_type, char > equipmentconfiguration_traits;

    const equipmentconfiguration_sequence&
    equipmentconfiguration () const;

    equipmentconfiguration_sequence&
    equipmentconfiguration ();

    void
    equipmentconfiguration (const equipmentconfiguration_sequence& s);

    // fins
    //
    typedef ::streit::equipmentPieceType fins_type;
    typedef ::xsd::cxx::tree::sequence< fins_type > fins_sequence;
    typedef fins_sequence::iterator fins_iterator;
    typedef fins_sequence::const_iterator fins_const_iterator;
    typedef ::xsd::cxx::tree::traits< fins_type, char > fins_traits;

    const fins_sequence&
    fins () const;

    fins_sequence&
    fins ();

    void
    fins (const fins_sequence& s);

    // gloves
    //
    typedef ::streit::equipmentPieceType gloves_type;
    typedef ::xsd::cxx::tree::sequence< gloves_type > gloves_sequence;
    typedef gloves_sequence::iterator gloves_iterator;
    typedef gloves_sequence::const_iterator gloves_const_iterator;
    typedef ::xsd::cxx::tree::traits< gloves_type, char > gloves_traits;

    const gloves_sequence&
    gloves () const;

    gloves_sequence&
    gloves ();

    void
    gloves (const gloves_sequence& s);

    // knife
    //
    typedef ::streit::equipmentPieceType knife_type;
    typedef ::xsd::cxx::tree::sequence< knife_type > knife_sequence;
    typedef knife_sequence::iterator knife_iterator;
    typedef knife_sequence::const_iterator knife_const_iterator;
    typedef ::xsd::cxx::tree::traits< knife_type, char > knife_traits;

    const knife_sequence&
    knife () const;

    knife_sequence&
    knife ();

    void
    knife (const knife_sequence& s);

    // lead
    //
    typedef ::streit::equipmentPieceType lead_type;
    typedef ::xsd::cxx::tree::sequence< lead_type > lead_sequence;
    typedef lead_sequence::iterator lead_iterator;
    typedef lead_sequence::const_iterator lead_const_iterator;
    typedef ::xsd::cxx::tree::traits< lead_type, char > lead_traits;

    const lead_sequence&
    lead () const;

    lead_sequence&
    lead ();

    void
    lead (const lead_sequence& s);

    // light
    //
    typedef ::streit::equipmentPieceType light_type;
    typedef ::xsd::cxx::tree::sequence< light_type > light_sequence;
    typedef light_sequence::iterator light_iterator;
    typedef light_sequence::const_iterator light_const_iterator;
    typedef ::xsd::cxx::tree::traits< light_type, char > light_traits;

    const light_sequence&
    light () const;

    light_sequence&
    light ();

    void
    light (const light_sequence& s);

    // mask
    //
    typedef ::streit::equipmentPieceType mask_type;
    typedef ::xsd::cxx::tree::sequence< mask_type > mask_sequence;
    typedef mask_sequence::iterator mask_iterator;
    typedef mask_sequence::const_iterator mask_const_iterator;
    typedef ::xsd::cxx::tree::traits< mask_type, char > mask_traits;

    const mask_sequence&
    mask () const;

    mask_sequence&
    mask ();

    void
    mask (const mask_sequence& s);

    // rebreather
    //
    typedef ::streit::rebreatherType rebreather_type;
    typedef ::xsd::cxx::tree::sequence< rebreather_type > rebreather_sequence;
    typedef rebreather_sequence::iterator rebreather_iterator;
    typedef rebreather_sequence::const_iterator rebreather_const_iterator;
    typedef ::xsd::cxx::tree::traits< rebreather_type, char > rebreather_traits;

    const rebreather_sequence&
    rebreather () const;

    rebreather_sequence&
    rebreather ();

    void
    rebreather (const rebreather_sequence& s);

    // regulator
    //
    typedef ::streit::equipmentPieceType regulator_type;
    typedef ::xsd::cxx::tree::sequence< regulator_type > regulator_sequence;
    typedef regulator_sequence::iterator regulator_iterator;
    typedef regulator_sequence::const_iterator regulator_const_iterator;
    typedef ::xsd::cxx::tree::traits< regulator_type, char > regulator_traits;

    const regulator_sequence&
    regulator () const;

    regulator_sequence&
    regulator ();

    void
    regulator (const regulator_sequence& s);

    // scooter
    //
    typedef ::streit::equipmentPieceType scooter_type;
    typedef ::xsd::cxx::tree::sequence< scooter_type > scooter_sequence;
    typedef scooter_sequence::iterator scooter_iterator;
    typedef scooter_sequence::const_iterator scooter_const_iterator;
    typedef ::xsd::cxx::tree::traits< scooter_type, char > scooter_traits;

    const scooter_sequence&
    scooter () const;

    scooter_sequence&
    scooter ();

    void
    scooter (const scooter_sequence& s);

    // suit
    //
    typedef ::streit::suitType suit_type;
    typedef ::xsd::cxx::tree::sequence< suit_type > suit_sequence;
    typedef suit_sequence::iterator suit_iterator;
    typedef suit_sequence::const_iterator suit_const_iterator;
    typedef ::xsd::cxx::tree::traits< suit_type, char > suit_traits;

    const suit_sequence&
    suit () const;

    suit_sequence&
    suit ();

    void
    suit (const suit_sequence& s);

    // tank
    //
    typedef ::streit::tankType tank_type;
    typedef ::xsd::cxx::tree::sequence< tank_type > tank_sequence;
    typedef tank_sequence::iterator tank_iterator;
    typedef tank_sequence::const_iterator tank_const_iterator;
    typedef ::xsd::cxx::tree::traits< tank_type, char > tank_traits;

    const tank_sequence&
    tank () const;

    tank_sequence&
    tank ();

    void
    tank (const tank_sequence& s);

    // variouspieces
    //
    typedef ::streit::equipmentPieceType variouspieces_type;
    typedef ::xsd::cxx::tree::sequence< variouspieces_type > variouspieces_sequence;
    typedef variouspieces_sequence::iterator variouspieces_iterator;
    typedef variouspieces_sequence::const_iterator variouspieces_const_iterator;
    typedef ::xsd::cxx::tree::traits< variouspieces_type, char > variouspieces_traits;

    const variouspieces_sequence&
    variouspieces () const;

    variouspieces_sequence&
    variouspieces ();

    void
    variouspieces (const variouspieces_sequence& s);

    // videocamera
    //
    typedef ::streit::videocameraType videocamera_type;
    typedef ::xsd::cxx::tree::sequence< videocamera_type > videocamera_sequence;
    typedef videocamera_sequence::iterator videocamera_iterator;
    typedef videocamera_sequence::const_iterator videocamera_const_iterator;
    typedef ::xsd::cxx::tree::traits< videocamera_type, char > videocamera_traits;

    const videocamera_sequence&
    videocamera () const;

    videocamera_sequence&
    videocamera ();

    void
    videocamera (const videocamera_sequence& s);

    // watch
    //
    typedef ::streit::equipmentPieceType watch_type;
    typedef ::xsd::cxx::tree::sequence< watch_type > watch_sequence;
    typedef watch_sequence::iterator watch_iterator;
    typedef watch_sequence::const_iterator watch_const_iterator;
    typedef ::xsd::cxx::tree::traits< watch_type, char > watch_traits;

    const watch_sequence&
    watch () const;

    watch_sequence&
    watch ();

    void
    watch (const watch_sequence& s);

    // Constructors.
    //
    equipmentType ();

    equipmentType (const ::xercesc::DOMElement& e,
                   ::xml_schema::flags f = 0,
                   ::xml_schema::container* c = 0);

    equipmentType (const equipmentType& x,
                   ::xml_schema::flags f = 0,
                   ::xml_schema::container* c = 0);

    virtual equipmentType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    equipmentType&
    operator= (const equipmentType& x);

    virtual 
    ~equipmentType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    boots_sequence boots_;
    buoyancycontroldevice_sequence buoyancycontroldevice_;
    camera_sequence camera_;
    compass_sequence compass_;
    compressor_sequence compressor_;
    divecomputer_sequence divecomputer_;
    equipmentconfiguration_sequence equipmentconfiguration_;
    fins_sequence fins_;
    gloves_sequence gloves_;
    knife_sequence knife_;
    lead_sequence lead_;
    light_sequence light_;
    mask_sequence mask_;
    rebreather_sequence rebreather_;
    regulator_sequence regulator_;
    scooter_sequence scooter_;
    suit_sequence suit_;
    tank_sequence tank_;
    variouspieces_sequence variouspieces_;
    videocamera_sequence videocamera_;
    watch_sequence watch_;
  };
}

#include <iosfwd>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream&, const equipmentType&);
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // EQUIPMENT_TYPE_HXX
