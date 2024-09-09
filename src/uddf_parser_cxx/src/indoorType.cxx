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

#include "indoorType.hxx"

#include "addressType.hxx"

#include "contactType.hxx"

#include "notesType.hxx"

namespace streit
{
  // indoorType
  //

  const indoorType::address_optional& indoorType::
  address () const
  {
    return this->address_;
  }

  indoorType::address_optional& indoorType::
  address ()
  {
    return this->address_;
  }

  void indoorType::
  address (const address_type& x)
  {
    this->address_.set (x);
  }

  void indoorType::
  address (const address_optional& x)
  {
    this->address_ = x;
  }

  void indoorType::
  address (::std::unique_ptr< address_type > x)
  {
    this->address_.set (std::move (x));
  }

  const indoorType::contact_optional& indoorType::
  contact () const
  {
    return this->contact_;
  }

  indoorType::contact_optional& indoorType::
  contact ()
  {
    return this->contact_;
  }

  void indoorType::
  contact (const contact_type& x)
  {
    this->contact_.set (x);
  }

  void indoorType::
  contact (const contact_optional& x)
  {
    this->contact_ = x;
  }

  void indoorType::
  contact (::std::unique_ptr< contact_type > x)
  {
    this->contact_.set (std::move (x));
  }

  const indoorType::notes_optional& indoorType::
  notes () const
  {
    return this->notes_;
  }

  indoorType::notes_optional& indoorType::
  notes ()
  {
    return this->notes_;
  }

  void indoorType::
  notes (const notes_type& x)
  {
    this->notes_.set (x);
  }

  void indoorType::
  notes (const notes_optional& x)
  {
    this->notes_ = x;
  }

  void indoorType::
  notes (::std::unique_ptr< notes_type > x)
  {
    this->notes_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // indoorType
  //

  indoorType::
  indoorType (const name_type& name)
  : ::streit::simpleNamedType (name),
    address_ (this),
    contact_ (this),
    notes_ (this)
  {
  }

  indoorType::
  indoorType (const indoorType& x,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::streit::simpleNamedType (x, f, c),
    address_ (x.address_, f, this),
    contact_ (x.contact_, f, this),
    notes_ (x.notes_, f, this)
  {
  }

  indoorType::
  indoorType (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f,
              ::xml_schema::container* c)
  : ::streit::simpleNamedType (e, f | ::xml_schema::flags::base, c),
    address_ (this),
    contact_ (this),
    notes_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void indoorType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    this->::streit::simpleNamedType::parse (p, f);

    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // address
      //
      if (n.name () == "address" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< address_type > r (
          address_traits::create (i, f, this));

        if (!this->address_)
        {
          this->address_.set (::std::move (r));
          continue;
        }
      }

      // contact
      //
      if (n.name () == "contact" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< contact_type > r (
          contact_traits::create (i, f, this));

        if (!this->contact_)
        {
          this->contact_.set (::std::move (r));
          continue;
        }
      }

      // notes
      //
      if (n.name () == "notes" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< notes_type > r (
          notes_traits::create (i, f, this));

        if (!this->notes_)
        {
          this->notes_.set (::std::move (r));
          continue;
        }
      }

      break;
    }
  }

  indoorType* indoorType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class indoorType (*this, f, c);
  }

  indoorType& indoorType::
  operator= (const indoorType& x)
  {
    if (this != &x)
    {
      static_cast< ::streit::simpleNamedType& > (*this) = x;
      this->address_ = x.address_;
      this->contact_ = x.contact_;
      this->notes_ = x.notes_;
    }

    return *this;
  }

  indoorType::
  ~indoorType ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const indoorType& i)
  {
    o << static_cast< const ::streit::simpleNamedType& > (i);

    if (i.address ())
    {
      o << ::std::endl << "address: " << *i.address ();
    }

    if (i.contact ())
    {
      o << ::std::endl << "contact: " << *i.contact ();
    }

    if (i.notes ())
    {
      o << ::std::endl << "notes: " << *i.notes ();
    }

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

