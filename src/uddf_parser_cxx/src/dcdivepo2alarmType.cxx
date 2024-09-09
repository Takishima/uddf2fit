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

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "dcdivepo2alarmType.hxx"

#include "dcalarmType.hxx"

namespace streit
{
  // dcdivepo2alarmType
  //

  const dcdivepo2alarmType::maximumpo2_type& dcdivepo2alarmType::
  maximumpo2 () const
  {
    return this->maximumpo2_.get ();
  }

  dcdivepo2alarmType::maximumpo2_type& dcdivepo2alarmType::
  maximumpo2 ()
  {
    return this->maximumpo2_.get ();
  }

  void dcdivepo2alarmType::
  maximumpo2 (const maximumpo2_type& x)
  {
    this->maximumpo2_.set (x);
  }

  const dcdivepo2alarmType::dcalarm_type& dcdivepo2alarmType::
  dcalarm () const
  {
    return this->dcalarm_.get ();
  }

  dcdivepo2alarmType::dcalarm_type& dcdivepo2alarmType::
  dcalarm ()
  {
    return this->dcalarm_.get ();
  }

  void dcdivepo2alarmType::
  dcalarm (const dcalarm_type& x)
  {
    this->dcalarm_.set (x);
  }

  void dcdivepo2alarmType::
  dcalarm (::std::unique_ptr< dcalarm_type > x)
  {
    this->dcalarm_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // dcdivepo2alarmType
  //

  dcdivepo2alarmType::
  dcdivepo2alarmType (const maximumpo2_type& maximumpo2,
                      const dcalarm_type& dcalarm)
  : ::xml_schema::type (),
    maximumpo2_ (maximumpo2, this),
    dcalarm_ (dcalarm, this)
  {
  }

  dcdivepo2alarmType::
  dcdivepo2alarmType (const maximumpo2_type& maximumpo2,
                      ::std::unique_ptr< dcalarm_type > dcalarm)
  : ::xml_schema::type (),
    maximumpo2_ (maximumpo2, this),
    dcalarm_ (std::move (dcalarm), this)
  {
  }

  dcdivepo2alarmType::
  dcdivepo2alarmType (const dcdivepo2alarmType& x,
                      ::xml_schema::flags f,
                      ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    maximumpo2_ (x.maximumpo2_, f, this),
    dcalarm_ (x.dcalarm_, f, this)
  {
  }

  dcdivepo2alarmType::
  dcdivepo2alarmType (const ::xercesc::DOMElement& e,
                      ::xml_schema::flags f,
                      ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    maximumpo2_ (this),
    dcalarm_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void dcdivepo2alarmType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // maximumpo2
      //
      if (n.name () == "maximumpo2" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        if (!maximumpo2_.present ())
        {
          this->maximumpo2_.set (maximumpo2_traits::create (i, f, this));
          continue;
        }
      }

      // dcalarm
      //
      if (n.name () == "dcalarm" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< dcalarm_type > r (
          dcalarm_traits::create (i, f, this));

        if (!dcalarm_.present ())
        {
          this->dcalarm_.set (::std::move (r));
          continue;
        }
      }

      break;
    }

    if (!maximumpo2_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "maximumpo2",
        "http://www.streit.cc/uddf/3.2/");
    }

    if (!dcalarm_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "dcalarm",
        "http://www.streit.cc/uddf/3.2/");
    }
  }

  dcdivepo2alarmType* dcdivepo2alarmType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class dcdivepo2alarmType (*this, f, c);
  }

  dcdivepo2alarmType& dcdivepo2alarmType::
  operator= (const dcdivepo2alarmType& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->maximumpo2_ = x.maximumpo2_;
      this->dcalarm_ = x.dcalarm_;
    }

    return *this;
  }

  dcdivepo2alarmType::
  ~dcdivepo2alarmType ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const dcdivepo2alarmType& i)
  {
    o << ::std::endl << "maximumpo2: " << i.maximumpo2 ();
    o << ::std::endl << "dcalarm: " << i.dcalarm ();
    return o;
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

